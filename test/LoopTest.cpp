// Copyright 2017 <ggarber@github>

#include "gtest/gtest.h"

#include "Loop.hpp"

using uvcpp::Loop;

class LoopTest: public ::testing::Test {
 protected:
  Loop loop;
};

TEST_F(LoopTest, Constructor) {
}

TEST_F(LoopTest, Run) {
  loop.Run();
}

TEST_F(LoopTest, CreateUdpSocket) {
  auto udp = loop.udp();
}
