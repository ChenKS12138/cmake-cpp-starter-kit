#include <iostream>
#include <string>
#include <vector>

#include "absl/log/globals.h"
#include "absl/log/initialize.h"
#include "absl/log/log.h"
#include "absl/strings/str_format.h"
#include "foo.h"

int main() {
    using namespace std;

    absl::InitializeLog();

    int ret = Foo::add(1, 2);
    cout << absl::StrFormat("1+1=%d", ret) << endl;

    vector<string> v{"aaa", "bbb", "cccc"};
    LOG(ERROR) << Foo::JoinList(v);

    return 0;
}
