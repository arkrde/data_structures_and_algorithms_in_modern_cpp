#ifndef ITER_COMPARE_AND_SWAP_HPP
#define ITER_COMPARE_AND_SWAP_HPP

#include <utility>
#include <functional>
#include <iterator>

namespace utilities {

using std::iter_swap;

/**
 * @brief Compares the values of two iterators and swaps if the first one is
 * smaller than the second
 */
template <typename FwdIter, typename Comparator>
void iter_compare_and_swap(FwdIter a1, FwdIter a2, Comparator comp) {
    if (comp(*a1, *a2)) {
        iter_swap(a1, a2);
    }
}

/**
 * @brief Compares the values of two iterators and swaps if the first one is
 * smaller than the second
 */
template <typename FwdIter>
void iter_compare_and_swap(FwdIter a1, FwdIter a2) {
    using value_type = typename std::iterator_traits<FwdIter>::value_type;
    iter_compare_and_swap(a1, a2, std::less<value_type>());
}

} // namespace utilities

#endif // ITER_COMPARE_AND_SWAP_HPP