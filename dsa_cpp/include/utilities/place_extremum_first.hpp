#ifndef PLACE_EXTREMUM_FIRST_HPP
#define PLACE_EXTREMUM_FIRST_HPP

#include <iterator>
#include "utilities/iter_compare_and_swap.hpp"

namespace utilities {

using utilities::iter_compare_and_swap;

template <typename RandomAccessIter, typename Comp>
void
place_extremum_first(RandomAccessIter first,
                    RandomAccessIter last,
                    Comp comparator) {
  if (first == last) {
    return;
  }
  if (last == first + 1) {
    return;
  }
  for (auto iter = last - 1; iter != first; --iter) {
    iter_compare_and_swap(iter, iter - 1, comparator);
  }
}

} // namespace utilities

#endif // PLACE_MINIMUM_FIRST_HPP