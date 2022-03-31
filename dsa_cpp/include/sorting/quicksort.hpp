#ifndef QUICKSORT_HPP
#define QUICKSORT_HPP

#include <iterator>
#include "quicksort_partition_policies/twoway_partition.hpp"

namespace sorting {

template <typename Iter, typename Comparator, typename PartitionPolicy>
void quicksort(Iter begin, Iter end, PartitionPolicy partition,
               Comparator comp) {
    if (end - begin <= 1) {
        return;
    }
    auto iter = partition(begin, end, comp);

    if (end - iter > iter - begin) {
        quicksort(begin, iter, partition, comp);
        quicksort(iter + 1, end, partition, comp);
    } else {
        quicksort(iter + 1, end, partition, comp);
        quicksort(begin, iter, partition, comp);
    }
}

template <typename Iter, typename Comparator>
void two_way_quicksort(Iter begin, Iter end, Comparator comp) {
    using quicksort::two_way_partition;
    return quicksort(begin, end, two_way_partition<Iter, Comparator>(), comp);
}

template <typename Iter>
void two_way_quicksort(Iter begin, Iter end) {
    using quicksort::two_way_partition;
    using value_type = typename std::iterator_traits<Iter>::value_type;
    std::less<value_type> comp;
    return quicksort(begin, end,
                     two_way_partition<Iter, std::less<value_type>>(), comp);
}

} // namespace sorting

#endif