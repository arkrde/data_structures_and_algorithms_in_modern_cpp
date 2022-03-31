#ifndef QUICKSORT_HPP
#define QUICKSORT_HPP

#include <iterator>
#include "quicksort_partition_policies/twoway_partition.hpp"
#include "sorting/insertionsort.hpp"

namespace sorting {

template <typename Iter, typename Comparator, typename PartitionPolicy>
void quicksort(Iter begin, Iter end, PartitionPolicy partition,
               Comparator comp, size_t subfile_size = 1) {
    if (end - begin <= 1) {
        return;
    }
    using sorting::insertion_sort;

    if (end - begin < subfile_size) {
        insertion_sort(begin, end, comp);
        return;
    }
    auto iter = partition(begin, end, comp, subfile_size);
    if (end - iter > iter - begin) {
        quicksort(begin, iter, partition, comp);
        quicksort(iter + 1, end, partition, comp);
    } else {
        quicksort(iter + 1, end, partition, comp);
        quicksort(begin, iter, partition, comp);
    }
}

template <typename Iter, typename Comparator>
void two_way_quicksort(Iter begin, Iter end, Comparator comp, size_t subfile_size = 1) {
    using quicksort::two_way_partition;
    return quicksort(begin, end, two_way_partition<Iter, Comparator>(), comp, subfile_size);
}

template <typename Iter>
void two_way_quicksort(Iter begin, Iter end) {
    using quicksort::two_way_partition;
    using value_type = typename std::iterator_traits<Iter>::value_type;
    std::less<value_type> comp;
    return quicksort(begin, end,
                     two_way_partition<Iter, std::less<value_type>>(), comp, 1);
}

} // namespace sorting

#endif