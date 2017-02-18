// Copyright 2017 <ggarber@github>

#ifndef SRC_TCP_HPP_
#define SRC_TCP_HPP_

#include <uv.h>

#include "Socket.hpp"

namespace uvcpp {

class Loop;

class TcpSocket: public Socket {
 public:
  explicit TcpSocket(Loop* loop);
  ~TcpSocket();

  void close();

  uv_tcp_t* ptr() { return &socket_; }

 private:
  uv_tcp_t socket_;
};

class TcpAcceptor: public Socket {
 public:
  explicit TcpAcceptor(Loop* loop);
  ~TcpAcceptor();

  void close();

  uv_tcp_t* ptr() { return &socket_; }

 private:
  uv_tcp_t socket_;
};

}  // namespace uvcpp

#endif  // SRC_TCP_HPP_
