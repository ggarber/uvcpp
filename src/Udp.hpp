// Copyright 2017 <ggarber@github>

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
  void Listen();
  void Listen(ushort port);
  void Close();

  void Send(const Buffer& data);

  uv_udp_t* ptr() { return &socket_; }

  std::function<void(const Buffer&)> Data;

 private:
  void OnSent(const Buffer& data);
  // void OnRecv(const Buffer& data, const IPEndPoint& ep);
 private:
  uv_udp_t socket_;
};

}  // namespace uvcpp

#endif  // SRC_UDP_HPP_
