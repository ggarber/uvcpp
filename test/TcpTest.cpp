// Copyright 2017 <ggarber@github>

#include "gtest/gtest.h"

#include "Loop.hpp"
#include "Tcp.hpp"

using uvcpp::Loop;
using uvcpp::TcpSocket;

class TcpSocketTest: public ::testing::Test {
 protected:
  TcpSocketTest(): tcp(&loop) {
    // You can do set-up work for each test here.
  }

  virtual ~TcpSocketTest() {
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

  Loop loop;
  TcpSocket tcp;
};

TEST_F(TcpSocketTest, SmokeTest) {
}
