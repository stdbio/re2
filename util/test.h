// Copyright 2009 The RE2 Authors.  All Rights Reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

#ifndef UTIL_TEST_H_
#define UTIL_TEST_H_

#include "util/util.h"
#include "util/logging.h"

namespace testing {
    std::string TempDir();
}  // namespace testing

#define TEST(x, y) \
    void x##y(void); \
    TestRegisterer r##x##y(x##y, # x "." # y); \
    void x##y(void)

void RegisterTest(void (*)(void), const char *);

class TestRegisterer {
public:
    TestRegisterer(void (*fn)(void), const char *s) {
        RegisterTest(fn, s);
    }
};

// fatal assertions
#define ASSERT_TRUE RE2_CHECK
#define ASSERT_FALSE(x) RE2_CHECK(!(x))
#define ASSERT_EQ RE2_CHECK_EQ
#define ASSERT_NE RE2_CHECK_NE
#define ASSERT_LT RE2_CHECK_LT
#define ASSERT_LE RE2_CHECK_LE
#define ASSERT_GT RE2_CHECK_GT
#define ASSERT_GE RE2_CHECK_GE

// nonfatal assertions
// TODO(rsc): Do a better job?
#define EXPECT_TRUE RE2_CHECK
#define EXPECT_FALSE(x) RE2_CHECK(!(x))
#define EXPECT_EQ RE2_CHECK_EQ
#define EXPECT_NE RE2_CHECK_NE
#define EXPECT_LT RE2_CHECK_LT
#define EXPECT_LE RE2_CHECK_LE
#define EXPECT_GT RE2_CHECK_GT
#define EXPECT_GE RE2_CHECK_GE

#endif  // UTIL_TEST_H_
