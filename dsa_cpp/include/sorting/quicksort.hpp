#ifndef QUICKSORT_HPP
#define QUICKSORT_HPP

#include <iterator>
#include "quicksort_partition_policies/twoway_partition.hpp"
#include "sorting/insertionsort.hpp"

namespace sorting {

template <typename Iter, typename Comparator, typename PartitionPolicy>
void quicksort(Iter begin, Iter end, PartitionPolicy partition, Comparator comp,
               size_t subfile_size) {
    if (end - begin < subfile_size) {
        return;
    }
    std::vector<Iter> pivots = partition(begin, end, comp, subfile_size);
    
    auto e = pivots.begin();
    auto b = begin;
    while (e != pivots.end()) {
        quicksort(b, *e, partition, comp, subfile_size);
        b = *e + 1;
        ++e;
    }
    quicksort(b, end, partition, comp, subfile_size);
    if (subfile_size > 1) {
        insertion_sort(begin, end, comp);
    }
    
}

template <typename Iter, typename Comparator>
void two_way_quicksort(Iter begin, Iter end, Comparator comp,
                       size_t subfile_size = 1) {
    using partition_policy::two_way_partition;
    quicksort(begin, end, two_way_partition<Iter, Comparator>(), comp,
              subfile_size);
}

template <typename Iter>
void two_way_quicksort(Iter begin, Iter end) {
    using partition_policy::two_way_partition;
    using value_type = typename std::iterator_traits<Iter>::value_type;
    std::less<value_type> comp;
    quicksort(begin, end, two_way_partition<Iter, std::less<value_type>>(),
              comp, 1);
}

} // namespace sorting

#endif