#ifndef MEDIAN_OF_THREE_QUICKSORT_HPP
#define MEDIAN_OF_THREE_QUICKSORT_HPP

#include <iterator>
#include "quicksort_partition_policies/twoway_partition.hpp"
#include "sorting/insertionsort.hpp"
#include "utilities/iter_compare_and_swap.hpp"

namespace sorting {

template <typename Iter, typename Comparator, typename PartitionPolicy>
void quicksort(Iter begin, Iter end, PartitionPolicy partition, Comparator comp,
               size_t subfile_size = 3) {
    assert(subfile_size >= 3);
    auto d = end - begin;
    if (d < subfile_size) {
        return;
    }

    Iter mid = begin + d / 2;
    std::iter_swap(mid, end - 2);

    using utilities::iter_compare_and_swap;
    iter_compare_and_swap(end - 2, begin, comp);
    iter_compare_and_swap(end - 1, begin, comp);
    iter_compare_and_swap(end - 1, end - 2, comp);

    std::vector<Iter> pivots = partition(begin, end, comp, subfile_size);

    auto e = pivots.begin();
    auto b = begin;
    while (e != pivots.end()) {
        quicksort(b, *e, partition, comp, subfile_size);
        b = *e + 1;
        ++e;
    }
    quicksort(b, end, partition, comp, subfile_size);
}

template <typename Iter, typename Comparator>
void two_way_quicksort(Iter begin, Iter end, Comparator comp,
                       size_t subfile_size = 3) {
    using partition_policy::two_way_partition;
    quicksort(begin, end, two_way_partition<Iter, Comparator>(), comp,
              subfile_size);
    using sorting::insertion_sort;
    insertion_sort(begin, end, comp);
}

} // namespace sorting

#endif