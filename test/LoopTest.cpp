// Copyright 2017 <ggarber@github>

#include "gtest/gtest.h"

#include "Loop.hpp"

using uvcpp::Loop;

class LoopTest: public ::testing::Test {
 protected:
  LoopTest() {
    // You can do set-up work for each test here.
  }

  virtual ~LoopTest() {
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
  Loop loop;
};

TEST_F(LoopTest, Constructor) {
}

TEST_F(LoopTest, Run) {
  loop.run();
}

TEST_F(LoopTest, CreateUdpSocket) {
  auto udp = loop.udp();
}
