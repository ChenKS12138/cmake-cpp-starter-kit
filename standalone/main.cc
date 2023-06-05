#include <iostream>
#include <string>
#include <vector>

#include "absl/base/log_severity.h"
#include "absl/log/globals.h"
#include "absl/log/initialize.h"
#include "absl/log/log.h"
#include "absl/strings/str_format.h"
#include "foo.h"

int main() {
    using namespace std;

    absl::SetStderrThreshold(absl::LogSeverity::kInfo);
    absl::InitializeLog();

    int ret = Foo::add(1, 2);
    LOG(INFO) << absl::StrFormat("1+1=%d", ret) << endl;

    vector<string> v{"aaa", "bbb", "cccc"};
    LOG(INFO) << Foo::JoinList(v);

    LOG(INFO) << "done"s;

    return 0;
}
