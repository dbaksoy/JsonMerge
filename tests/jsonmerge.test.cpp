#include "gtest/gtest.h"

#include "bouncmpe/jsonmerge.hpp"

TEST(MyTests, Test1)
{
  int a = 10;
  int b = 12;

  int result = bouncmpe::add_two_integer(a, b);
  int expected = 22;

  EXPECT_EQ(result, expected);
}

TEST(MyTests, Test2)
{
  boost::json::value target = {{"key1", "v1"}, {"key2", "a"}};
  boost::json::value patch = {{"key1", "v2"}};

  boost::json::value result = bouncmpe::jsonmerge(target, patch);
  boost::json::value expected = {{"key1", "v2"}, {"key2", "a"}};

  EXPECT_EQ(result, expected);
}

// Complete the test suite by writing more tests...

TEST(MyTests, Test3)
{
  boost::json::value target = bouncmpe::parseJson("../../data/test1/document1.json");
  boost::json::value patch = bouncmpe::parseJson("../../data/test1/document1.patch.json");

  boost::json::value merged = bouncmpe::jsonmerge(target, patch);
  bouncmpe::jsonwrite(merged, "../../data/test1/document1.merged.json");

  boost::json::value result = bouncmpe::parseJson("../../data/test1/document1.merged.json");
  boost::json::value expected = bouncmpe::parseJson("../../data/test1/document1.result.json");

  EXPECT_EQ(result, expected);
}

TEST(MyTests, Test4)
{
  boost::json::value target = bouncmpe::parseJson("../../data/test2/document2.json");
  boost::json::value patch = bouncmpe::parseJson("../../data/test2/document2.patch.json");

  boost::json::value merged = bouncmpe::jsonmerge(target, patch);
  bouncmpe::jsonwrite(merged, "../../data/test2/document2.merged.json");

  boost::json::value result = bouncmpe::parseJson("../../data/test2/document2.merged.json");
  boost::json::value expected = bouncmpe::parseJson("../../data/test2/document2.result.json");

  EXPECT_EQ(result, expected);
}
// When is it a good time to stop writing more tests?
