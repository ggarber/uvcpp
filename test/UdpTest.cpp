// Copyright 2017 <ggarber@github>

#include <gtest/gtest.h>

#include <mutex>  // NOLINT
#include <condition_variable>  // NOLINT

#include "Loop.hpp"
#include "Udp.hpp"

using uvcpp::Loop;
using uvcpp::UdpSocket;

class UdpSocketTest: public ::testing::Test {
 protected:
  UdpSocketTest(): udp(&loop) {
  }

  virtual ~UdpSocketTest() {
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
  UdpSocket udp;
};

TEST_F(UdpSocketTest, ListenSpecificPort) {
  udp.Listen(6868);
}

TEST_F(UdpSocketTest, ListenRandomPort) {
  udp.Listen();
}

TEST_F(UdpSocketTest, CloseWithoutListen) {
  udp.Close();
}

TEST_F(UdpSocketTest, CloseAfterListen) {
  udp.Listen();
  udp.Close();
}

TEST_F(UdpSocketTest, SendAndRecv) {
  UdpSocket udp1(&loop), udp2(&loop);

  udp1.Listen(); udp2.Listen(6868);

  udp2.Data = [this](auto buffer) -> void {
    // ASSERT_EQ(1, buffer.data.size());

    loop.Stop();
  };

  udp1.Send({ { 0x00 } });

  loop.Run();
}
