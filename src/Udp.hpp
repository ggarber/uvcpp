// Copyright 2017 <ggarber@github>

#ifndef SRC_UDP_HPP_
#define SRC_UDP_HPP_

#include <memory>
#include <functional>

#include "Socket.hpp"
#include "Buffer.hpp"

typedef struct uv_udp_s uv_udp_t;

namespace uvcpp {

class Loop;

class UdpSocket: public Socket {
 public:
  explicit UdpSocket(Loop* loop);
  ~UdpSocket();

 public:
  void Listen();
  void Listen(unsigned short port);
  void Close();

  void Send(const Buffer& data);

  uv_udp_t* ptr() { return socket_.get(); }

  std::function<void(const Buffer&)> Data;

 private:
  void OnSent(const Buffer& data);
  // void OnRecv(const Buffer& data, const IPEndPoint& ep);
 private:
  std::unique_ptr<uv_udp_t, void(*)(uv_udp_t*)> socket_;
};

}  // namespace uvcpp

#endif  // SRC_UDP_HPP_
