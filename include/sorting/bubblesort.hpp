#ifndef BUBBLESORT_HPP
#define BUBBLESORT_HPP

#include "utilities/iter_compare_and_swap.hpp"
#include <iterator>
#include <type_traits>

namespace sorting {

using utilities::iter_compare_and_swap;

/**
 * @brief bubblesort
 */
template <typename RandomIter, typename Comp,
          typename std::enable_if<std::is_same<
              typename std::iterator_traits<RandomIter>::iterator_category,
              std::random_access_iterator_tag>::value> * = nullptr>
void bubble_sort(RandomIter first, RandomIter last, Comp comparator) {
    while (first != last) {
        for (auto iter = last - 1; iter != first; --iter) {
            iter_compare_and_swap(iter, iter - 1, comparator);
        }
        ++first;
    }
}

template <typename RandomIter,
          typename std::enable_if<std::is_same<
              typename std::iterator_traits<RandomIter>::iterator_category,
              std::random_access_iterator_tag>::value> * = nullptr>
void bubble_sort(RandomIter first, RandomIter last) {
    using value_type = typename std::iterator_traits<RandomIter>::value_type;
    bubble_sort(first, last, std::less<value_type>());
}

} // namespace sorting

#endif