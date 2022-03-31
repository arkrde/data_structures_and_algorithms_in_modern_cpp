#ifndef BUBBLESORT_HPP
#define BUBBLESORT_HPP

#include "utilities/iter_compare_and_swap.hpp"
#include <iterator>

namespace sorting {

using utilities::iter_compare_and_swap;

/**
 * @brief bubblesort
 */
template <typename RandomIter, typename Comp>
void bubble_sort(RandomIter first, RandomIter last, Comp comparator) {
    while (first != last) {
        for (auto iter = last - 1; iter != first; --iter) {
            iter_compare_and_swap(iter, iter - 1, comparator);
        }
        ++first;
    }
}

template <typename RandomIterator>
void bubble_sort(RandomIterator first, RandomIterator last) {
    using value_type =
        typename std::iterator_traits<RandomIterator>::value_type;
    bubble_sort(first, last, std::less<value_type>());
}

} // namespace sorting

#endif 