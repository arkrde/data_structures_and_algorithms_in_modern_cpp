#ifndef THREEWAY_PARTITION_HPP
#define THREEWAY_PARTITION_HPP

#include <vector>
#include <utility>
#include "utilities/iter_compare_and_swap.hpp"

namespace partition_policy {

template <typename Iter, typename Comparator>
class three_way_partition {
private:
    std::pair<Iter, Iter> sample_pivot(Iter begin, Iter end, Comparator comp) {
        auto d = (end - begin) / 6;
        auto s1 = begin + d;
        auto s2 = s1 + d;
        auto s3 = s2 + d;
        auto s4 = s3 + d;
        auto s5 = s4 + d;
        using utilities::iter_compare_and_swap;
        iter_compare_and_swap(s1, s2, comp);
        iter_compare_and_swap(s4, s5, comp);
        iter_compare_and_swap(s1, s3, comp);
        iter_compare_and_swap(s2, s3, comp);
        iter_compare_and_swap(s1, s4, comp);
        iter_compare_and_swap(s3, s4, comp);
        iter_compare_and_swap(s2, s5, comp);
        iter_compare_and_swap(s2, s3, comp);

        return std::pair<Iter, Iter>{s2, s4};
    }
    std::vector<Iter> partition_impl(Iter begin, Iter end, Comparator comp,
                                     size_t subfile_size) {
        using std::iter_swap;
        using utilities::iter_compare_and_swap;

        assert(end - begin > 2);

        std::vector<Iter> ret;
        Iter p1 = begin;
        Iter p2 = begin;
        Iter p3 = end - 1;

        iter_compare_and_swap(p3, p1, comp);


        if (end - begin > subfile_size) {


            std::pair<Iter, Iter> pivots = sample_pivot(begin, end, comp);

            typename std::iterator_traits<Iter>::value_type low = *(pivots.first);
            typename std::iterator_traits<Iter>::value_type high = *(pivots.second);

            for (Iter iter = p2 + 1; iter < p3;) {
                if (comp(*iter, low)) {
                    iter_swap(p1 + 1, iter);
                    iter_swap(p1, p1 + 1);
                    ++p1;
                    if (p2 < p1) {
                        ++p2;
                    }
                    ++iter;
                } else if (comp(low, *iter) && comp(*iter, high)) {
                    // iter_swap(p2 + 1, iter);
                    ++p2;
                    ++iter;
                } else {
                    iter_swap(p3 - 1, iter);
                    iter_swap(p3 - 1, p3);
                    --p3;
                }
            }
        }

        ret.push_back(p1);
        ret.push_back(p3);
        return ret;
    }

public:
    std::vector<Iter> operator()(Iter begin, Iter end, Comparator comp,
                                 size_t subfile_size = 1) {
        return partition_impl(begin, end, comp, subfile_size);
    }
};
} // namespace partition_policy

#endif