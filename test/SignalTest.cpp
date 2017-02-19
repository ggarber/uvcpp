// Copyright 2017 <ggarber@github>

#include "gtest/gtest.h"

#include "Signal.hpp"

using uvcpp::Signal;

class SignalTest: public ::testing::Test {
 protected:
  SignalTest() {
    // You can do set-up work for each test here.
  }

  virtual ~SignalTest() {
    // You can do clean-up work that doesn't throw exceptions here.
  }

  // If the constructor and destructor are not enough for setting up
  // and cleaning up each test, you can define the following methods:

  virtual void SetUp() {
    // Code here will be called immediately after the constructor (right
    // before each test).
  }

  virtual void TearDown() {
    // Code here will be called immediately after each test (right
    // before the destructor).
  }

  // Objects declared here can be used by all tests in the test case for Foo.
  Signal signal;
};

TEST_F(SignalTest, SmokeTest) {
}
