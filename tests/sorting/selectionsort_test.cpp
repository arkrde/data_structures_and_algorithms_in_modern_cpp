#include <gtest/gtest.h>
#include <vector>
#include <algorithm>
#include "sorting/selectionsort.hpp"

using sorting::selection_sort;

static constexpr int ShortSequenceLength = 100;
static constexpr int LongSequenceLength = 10000;

TEST(SortEval, ShortSequenceAscending) {
    std::vector<int> array(ShortSequenceLength);
    std::generate(std::begin(array), std::end(array), []() {
        return static_cast<int>(1000.0 * rand() / RAND_MAX);
    });
    selection_sort(array.begin(), array.end());
    EXPECT_EQ(std::is_sorted(array.cbegin(), array.cend()), true);
}

TEST(SortEval, ShortSequenceDescending) {
    std::vector<int> array(ShortSequenceLength);
    std::generate(std::begin(array), std::end(array), []() {
        return static_cast<int>(1000.0 * rand() / RAND_MAX);
    });
    selection_sort(array.begin(), array.end(), std::greater<int>());
    EXPECT_EQ(std::is_sorted(array.cbegin(), array.cend(), std::greater<int>()),
              true);
}

TEST(SortEval, LongSequenceAscending) {
    std::vector<int> array(LongSequenceLength);
    std::generate(std::begin(array), std::end(array), []() {
        return static_cast<int>(1000.0 * rand() / RAND_MAX);
    });
    selection_sort(array.begin(), array.end());
    EXPECT_EQ(std::is_sorted(array.cbegin(), array.cend()), true);
}

TEST(SortEval, LongSequenceDescending) {
    std::vector<int> array(LongSequenceLength);
    std::generate(std::begin(array), std::end(array), []() {
        return static_cast<int>(1000.0 * rand() / RAND_MAX);
    });
    selection_sort(array.begin(), array.end(), std::greater<int>());
    EXPECT_EQ(std::is_sorted(array.cbegin(), array.cend(), std::greater<int>()),
              true);
}