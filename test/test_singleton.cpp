#include <cstdint>

#include <gtest/gtest.h>

#include "design_patterns/singleton/singleton.h"

template class Singleton<int32_t>;

TEST(TestSingleton, SingletonCanGetAndSetMinimumData) {
    const int32_t data = INT32_MIN;
    Singleton<int32_t>::getInstance().setData(data);
    EXPECT_TRUE(data == Singleton<int32_t>::getInstance().getData());
}

TEST(TestSingleton, SingletonCanGetAndSetData) {
    const int32_t data = 3U;
    Singleton<int32_t>::getInstance().setData(data);
    EXPECT_TRUE(data == Singleton<int32_t>::getInstance().getData());
}

TEST(TestSingleton, SingletonCanGetAndSetMaximumData) {
    const int32_t data = INT32_MAX;
    Singleton<int32_t>::getInstance().setData(data);
    EXPECT_TRUE(data == Singleton<int32_t>::getInstance().getData());
}
