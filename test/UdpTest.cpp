// Copyright 2016 <ggarber@github>

// #include <mutex>
// #include <condition_variable>

#include "gtest/gtest.h"

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
  udp.listen(6868);
}

TEST_F(UdpSocketTest, ListenRandomPort) {
  udp.listen();
}

TEST_F(UdpSocketTest, CloseWithoutListen) {
  udp.close();
}

TEST_F(UdpSocketTest, CloseAfterListen) {
  udp.listen();
  udp.close();
}

TEST_F(UdpSocketTest, SendAndRecv) {
  UdpSocket udp1(&loop), udp2(&loop);
  udp1.listen(); udp2.listen(6868);

  std::mutex m;
  std::condition_variable cv;

  udp2.Data = [&](auto buffer) -> void {
    ASSERT_EQ(1, buffer.data.size());

    cv.notify_one();
  };

  udp1.send({ { 0x00 } });

  loop.run();

  std::unique_lock<std::mutex> lk(m);
  cv.wait(lk);
}
