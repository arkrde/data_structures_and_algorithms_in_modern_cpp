#ifndef INSERTION_SORT_HPP
#define INSERTION_SORT_HPP

#include <iterator>
#include <algorithm>
#include "utilities/place_extremum_first.hpp"

namespace sorting {

using std::min_element;
using utilities::place_extremum_first;

/**
 * @brief insertion sort: uses the optimizations from Sedgewick: Algorithms in
 * C++ - Section 6.3 Insetion Sort
 */
template <typename RandomAccessIter, typename Comparator>
void insertion_sort(RandomAccessIter first, RandomAccessIter last,
                    Comparator comp) {
    if (first == last) {
        return;
    }
    if (last == first + 1) {
        return;
    }
    // A first pass through the array to place the smallest/largest key in the
    // first position depending upon the `comp` function.
    place_extremum_first(first, last, comp);
    // Adaptive sort
    for (auto iter = first + 2; iter != last; ++iter) {
        auto it = iter;
        auto v = *it;
        while (comp(v, *(it - 1))) {
            *it = *(it - 1);
            --it;
        }
        *it = v;
    }
}

/**
 * @brief insertion sort: uses the optimizations from Sedgewick: Algorithms in
 * C++ - Section 6.3 Insetion Sort
 */
template <typename RandomAccessIter>
void insertion_sort(RandomAccessIter first, RandomAccessIter last) {
    using value_type =
        typename std::iterator_traits<RandomAccessIter>::value_type;
    insertion_sort(first, last, std::less<value_type>());
}
} // namespace sorting

#endif 
