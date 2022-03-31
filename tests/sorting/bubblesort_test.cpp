#include <gtest/gtest.h>
#include <vector>
#include <algorithm>
#include "sorting/bubblesort.hpp"

using sorting::bubble_sort;

static constexpr int ShortSequenceLength = 10;
static constexpr int LongSequenceLength = 10000;

TEST(SortEval, ShortSequenceAscending) {
    std::vector<int> array(ShortSequenceLength);
    std::generate(array.begin(), array.end(), []() {
        return static_cast<int>(1000.0 * rand() / RAND_MAX);
    });
    bubble_sort(array.begin(), array.end());
    EXPECT_EQ(std::is_sorted(array.cbegin(), array.cend()), true);
}

TEST(SortEval, ShortSequenceDescending) {
    std::vector<int> array(ShortSequenceLength);
    std::generate(array.begin(), array.end(), []() {
        return static_cast<int>(1000.0 * rand() / RAND_MAX);
    });
    bubble_sort(array.begin(), array.end(), std::greater<int>());
    EXPECT_EQ(std::is_sorted(array.cbegin(), array.cend(), std::greater<int>()),
              true);
}

TEST(SortEval, LongSequenceAscending) {
    std::vector<int> array(LongSequenceLength);
    std::generate(array.begin(), array.end(), []() {
        return static_cast<int>(1000.0 * rand() / RAND_MAX);
    });
    bubble_sort(array.begin(), array.end());
    EXPECT_EQ(std::is_sorted(array.cbegin(), array.cend()), true);
}

TEST(SortEval, LongSequenceDescending) {
    std::vector<int> array(LongSequenceLength);
    std::generate(array.begin(), array.end(), []() {
        return static_cast<int>(1000.0 * rand() / RAND_MAX);
    });
    bubble_sort(array.begin(), array.end(), std::greater<int>());
    EXPECT_EQ(std::is_sorted(array.cbegin(), array.cend(),
                             std::greater<int>()),
              true);
}