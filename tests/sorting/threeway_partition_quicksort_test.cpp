#include <gtest/gtest.h>
#include <vector>
#include <algorithm>
#include "sorting/quicksort.hpp"
#include "sorting/quicksort_partition_policies/threeway_partition.hpp"

using partition_policy::three_way_partition;
using sorting::quicksort;

static constexpr int ShortSequenceLength = 20;
static constexpr int LongSequenceLength = 10000;

TEST(SortEval, ShortSequenceAscending) {
    std::vector<int> array(ShortSequenceLength);
    std::generate(std::begin(array), std::end(array), []() {
        return static_cast<int>(1000.0 * rand() / RAND_MAX);
    });
    std::less<int> comp;
    three_way_partition<std::vector<int>::iterator, std::less<int>> partition;
    quicksort(array.begin(), array.end(), partition, comp, 16);
    EXPECT_EQ(std::is_sorted(array.cbegin(), array.cend(), comp), true);
}

TEST(SortEval, ShortSequenceDescending) {
    std::vector<int> array(ShortSequenceLength);
    std::generate(std::begin(array), std::end(array), []() {
        return static_cast<int>(1000.0 * rand() / RAND_MAX);
    });
    std::greater<int> comp;
    three_way_partition<std::vector<int>::iterator, std::greater<int>> partition;
    quicksort(array.begin(), array.end(), partition, comp, 16);
    EXPECT_EQ(std::is_sorted(array.cbegin(), array.cend(), comp), true);
}

TEST(SortEval, LongSequenceAscending) {
    std::vector<int> array(LongSequenceLength);
    std::generate(std::begin(array), std::end(array), []() {
        return static_cast<int>(1000.0 * rand() / RAND_MAX);
    });
    std::less<int> comp;
    three_way_partition<std::vector<int>::iterator, std::less<int>> partition;
    quicksort(array.begin(), array.end(), partition, comp, 16);
    EXPECT_EQ(std::is_sorted(array.cbegin(), array.cend(), comp), true);
}

TEST(SortEval, LongSequenceDescending) {
    std::vector<int> array(LongSequenceLength);
    std::generate(std::begin(array), std::end(array), []() {
        return static_cast<int>(1000.0 * rand() / RAND_MAX);
    });
    std::greater<int> comp;
    three_way_partition<std::vector<int>::iterator, std::greater<int>> partition;
    quicksort(array.begin(), array.end(), partition, comp, 16);
    EXPECT_EQ(std::is_sorted(array.cbegin(), array.cend(), comp), true);
}
