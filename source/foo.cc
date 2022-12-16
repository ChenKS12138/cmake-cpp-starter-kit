#include "foo.h"

#include "absl/strings/str_join.h"

int Foo::add(int a, int b) { return a + b; }

std::string Foo::JoinList(std::vector<std::string>& list) {
    return absl::StrJoin(list, ",");
}
