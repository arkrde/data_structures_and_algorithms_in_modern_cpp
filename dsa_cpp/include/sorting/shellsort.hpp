#ifndef SHELL_SORT_HPP
#define SHELL_SORT_HPP

#include <iterator>
#include <functional>
#include "utilities/iter_compare_and_swap.hpp"

namespace sorting {

template <typename RandomIter, typename Comp>
void shell_sort(RandomIter first, RandomIter last, Comp comparator) {
    int h = 1;
    while (h <= (last - first) / 9) {
        h = 3 * h + 1;
    }
    for (; h > 0; h /= 3) {
        for (auto begin = std::next(first, h); last - begin >= 0; ++begin) {
            auto iter = begin;
            auto v = *iter;
            while ((iter - first > h - 1) && (comparator(v, *(iter - h)))) {
                *iter = *(iter - h);
                iter = iter - h;
            }
            *iter = v;
        }
    }
}

template <typename RandomIter>
void shell_sort(RandomIter first, RandomIter last) {
    using value_type = typename std::iterator_traits<RandomIter>::value_type;
    shell_sort(first, last, std::less<value_type>());
}

} // namespace sorting

#endif 
