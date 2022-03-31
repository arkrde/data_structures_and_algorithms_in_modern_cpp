#include <gtest/gtest.h>
#include <vector>
#include <algorithm>
#include "sorting/quicksort.hpp"

using sorting::two_way_quicksort;

static constexpr int ShortSequenceLength = 10;
static constexpr int LongSequenceLength = 10000;

TEST(subfile_optim, ShortSequenceAscending) {
    std::vector<int> array(ShortSequenceLength);
    std::generate(std::begin(array), std::end(array), []() {
        return static_cast<int>(1000.0 * rand() / RAND_MAX);
    });
    two_way_quicksort(array.begin(), array.end(), std::less<int>(), 5);
    EXPECT_EQ(std::is_sorted(array.cbegin(), array.cend()), true);
}

TEST(subfile_optim, ShortSequenceDescending) {
    std::vector<int> array(ShortSequenceLength);
    std::generate(std::begin(array), std::end(array), []() {
        return static_cast<int>(1000.0 * rand() / RAND_MAX);
    });
    two_way_quicksort(array.begin(), array.end(), std::greater<int>(), 5);
    EXPECT_EQ(std::is_sorted(array.cbegin(), array.cend(), std::greater<int>()),
              true);
}


TEST(subfile_optim, LongSequenceAscending) {
    std::vector<int> array(LongSequenceLength);
    std::generate(std::begin(array), std::end(array), []() {
        return static_cast<int>(1000.0 * rand() / RAND_MAX);
    });
    two_way_quicksort(array.begin(), array.end(), std::less<int>(), 5);
    EXPECT_EQ(std::is_sorted(array.cbegin(), array.cend()), true);
}

TEST(subfile_optim, LongSequenceDescending) {
    std::vector<int> array(LongSequenceLength);
    std::generate(std::begin(array), std::end(array), []() {
        return static_cast<int>(1000.0 * rand() / RAND_MAX);
    });
    two_way_quicksort(array.begin(), array.end(), std::greater<int>(), 5);
    EXPECT_EQ(std::is_sorted(array.cbegin(), array.cend(), std::greater<int>()),
              true);
}