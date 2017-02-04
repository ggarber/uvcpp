// Copyright 2016 <ggarber@github>

#ifndef SRC_UDP_HPP_
#define SRC_UDP_HPP_

#include <uv.h>

#include <functional>

#include "Socket.hpp"
#include "Buffer.hpp"

namespace uvcpp {

class Loop;

class UdpSocket: public Socket {
 public:
  explicit UdpSocket(Loop* loop);
  ~UdpSocket();

 public:
  void listen();
  void listen(ushort port);
  void close();

  void send(const Buffer& data);

  uv_udp_t* ptr() { return &socket_; }

  // TODO(ggb): Signal
  std::function<void(const Buffer&)> Data;
 private:
  uv_udp_t socket_;
};

}  // namespace uvcpp

#endif  // SRC_UDP_HPP_
