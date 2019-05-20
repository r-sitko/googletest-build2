#include <gtest/gtest.h>

namespace {

int sum(int a, int b)
{
  return a + b;
}

TEST(LibaGtestMain, Basic)
{
  ASSERT_EQ(5, sum(2, 3));
}

}