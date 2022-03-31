#ifndef TWOWAY_PARTITION_HPP
#define TWOWAY_PARTITION_HPP

namespace quicksort {

template <typename Iter, typename Comparator>
class two_way_partition {
private:
    Iter partition_impl(Iter begin, Iter end, Comparator comp, size_t subfile_size) {
        if (end - begin <= 1) return end;
        auto pivot = --end;
        while (begin < end) {
            // Search from the beginning for the first element larger than the
            // pivot
            while (comp(*begin, *pivot) && begin < end) {
                ++begin;
            }
            --end;
            // Search from the end for the first element smaller than the pivot
            while (comp(*pivot, *end) && begin < end) {
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
            return end;
        }
        std::iter_swap(begin, pivot);
        return begin;
    }

public:
    Iter operator()(Iter begin, Iter end, Comparator comp, size_t subfile_size = 1) {
        return partition_impl(begin, end, comp, subfile_size);
    }
};
} // namespace quicksort

#endif