#ifndef SELECTIONSORT_HPP
#define SELECTIONSORT_HPP

#include <iterator>
#include <algorithm>
#include <utility>
#include "utilities/extremum.hpp"

namespace sorting {

using std::min_element;
using utilities::extremum;

template <typename RandomAccessIter, typename Comparator>
void selection_sort(RandomAccessIter first, RandomAccessIter last,
                    Comparator comp) {
    while (first != last) {
        RandomAccessIter ext = extremum(first, last, comp);
        if (first != last) {
            std::iter_swap(first, ext);
        }
        ++first;
    }
}

template <typename RandomAccessIter>
void selection_sort(RandomAccessIter first, RandomAccessIter last) {
    using value_type =
        typename std::iterator_traits<RandomAccessIter>::value_type;
    selection_sort(first, last, std::less<value_type>());
}

} // namespace sort
#endif