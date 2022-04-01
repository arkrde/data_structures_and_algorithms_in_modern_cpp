#ifndef THREEWAY_PARTITION_HPP
#define THREEWAY_PARTITION_HPP

#include <vector>
#include "utilities/iter_compare_and_swap.hpp"

namespace partition_policy {

template <typename Iter, typename Comparator>
class three_way_partition {
private:
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

            typename std::iterator_traits<Iter>::value_type low = *p1;
            typename std::iterator_traits<Iter>::value_type high = *p3;

            for (Iter iter = p2 + 1; iter < p3; ++iter) {
                if (comp(*iter, low)) {
                    iter_swap(p1 + 1, iter);
                    iter_swap(p1, p1 + 1);
                    ++p1;
                    if (p2 < p1) {
                        ++p2;
                    }
                } else if (comp(low, *iter) && comp(*iter, high)) {
                    iter_swap(p2 + 1, iter);
                    ++p2;
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
} // namespace quicksort

#endif