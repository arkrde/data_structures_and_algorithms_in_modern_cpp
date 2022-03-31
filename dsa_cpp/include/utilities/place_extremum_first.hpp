#ifndef PLACE_EXTREMUM_FIRST_HPP
#define PLACE_EXTREMUM_FIRST_HPP

#include <iterator>
#include "utilities/extremum.hpp"

namespace utilities {

using std::iter_swap;
using utilities::extremum;

template <typename RandomAccessIter, typename Comp>
void place_extremum_first(RandomAccessIter first, RandomAccessIter last,
                          Comp comparator) {
    if (first == last || last == first + 1) {
        return;
    }
    RandomAccessIter ext = extremum(first, last, comparator);
    if (ext != first) {
        iter_swap(first, ext);
    }
}

} // namespace utilities

#endif