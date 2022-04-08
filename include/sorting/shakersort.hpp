#ifndef SHAKER_SORT
#define SHAKER_SORT

#include <iterator>
#include "utilities/iter_compare_and_swap.hpp"

using utilities::iter_compare_and_swap;

namespace sorting {
/**
 * @brief Shaker-sort (bidirectional bubble sort)
 *
 * @tparam RandomIter
 * @tparam Comp
 * @param begin
 * @param end
 * @param comparator
 */
template <typename RandomIter, typename Comp>
void shaker_sort(RandomIter begin, RandomIter end, Comp comparator) {
    while (begin != end) {
        for (auto iter = end - 1; iter != begin; --iter) {
            iter_compare_and_swap(iter, iter - 1, comparator);
        }
        ++begin;
        if (begin == end) {
            break;
        }
        for (auto iter = begin + 1; iter != end; ++iter) {
            iter_compare_and_swap(iter, iter - 1, comparator);
        }
        --end;
    }
}

/**
 * @brief Shaker-sort (bidirectional bubble sort)
 *
 * @tparam RandomIter
 * @param begin
 * @param end
 */
template <typename RandomIter>
void shaker_sort(RandomIter begin, RandomIter end) {
    using value_type = typename std::iterator_traits<RandomIter>::value_type;
    shaker_sort(begin, end, std::less<value_type>());
}
} // namespace sort

#endif