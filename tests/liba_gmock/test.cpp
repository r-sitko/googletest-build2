#include <gmock/gmock.h>
#include <gtest/gtest.h>

namespace {

struct MockItem
{
  virtual ~MockItem() = default;
  MOCK_METHOD0(test, int());
};

TEST(LibaGmock, Basic)
{
  ::testing::StrictMock<MockItem> mockItem;
  EXPECT_CALL(mockItem, test());
  mockItem.test();
}

}