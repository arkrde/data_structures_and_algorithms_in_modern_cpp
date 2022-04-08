#ifndef TWOWAY_PARTITION_HPP
#define TWOWAY_PARTITION_HPP

#include <vector>

namespace partition_policy {

template <typename Iter, typename Comparator>
class two_way_partition {
private:
    std::vector<Iter> partition_impl(Iter begin, Iter end, Comparator comp,
                                     size_t subfile_size) {
        std::vector<Iter> ret;
        if (end - begin < subfile_size) {
            ret.push_back(end);
            return ret;
        }
        auto pivot = --end;
        while (begin < end) {
            // Search from the beginning for the first element larger than the
            // pivot
            while (begin < end && comp(*begin, *pivot)) {
                ++begin;
            }
            --end;
            // Search from the end for the first element smaller than the pivot
            while (begin < end && comp(*pivot, *end)) {
                --end;
            };

            if (begin >= end)
                break;
            // Exchange the two elements
            std::iter_swap(begin, end);
            ++begin;
        }
        if (comp(*pivot, *end)) {
            std::iter_swap(end, pivot);
            ret.push_back(end);
        } else {
            std::iter_swap(begin, pivot);
            ret.push_back(begin);
        }
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