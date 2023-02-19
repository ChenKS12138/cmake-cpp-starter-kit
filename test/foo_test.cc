#include "foo.h"
#include <vector>
#include "gtest/gtest.h"
#include <vector>
#include <string>

TEST(Foo, Add) {
  int operand_1 = 2;
  int operand_2 = 3;
  EXPECT_EQ(
    Foo::add(operand_1, operand_2),
    Foo::add(operand_2, operand_1)
  );
}

TEST(Foo,JoinList) {
  std::vector<std::string> v {"foo","bar"};
  EXPECT_EQ(Foo::JoinList(v), "foo,bar");
}
