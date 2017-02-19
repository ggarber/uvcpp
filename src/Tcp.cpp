// Copyright 2017 <ggarber@github>

#include "Tcp.hpp"

#include <exception>
#include <iostream>

#include "Uv.hpp"
#include "Loop.hpp"

using uvcpp::Loop;
using uvcpp::TcpSocket;
using uvcpp::TcpAcceptor;


TcpSocket::TcpSocket(Loop* loop) {
  uv_guard(uv_tcp_init(loop->ptr(), &socket_));
}

TcpSocket::~TcpSocket() {
  Close();
}

void TcpSocket::Close() {
  uv_close(uv_handle(ptr()), nullptr);
}

TcpAcceptor::TcpAcceptor(Loop* loop) {
  uv_guard(uv_tcp_init(loop->ptr(), &socket_));
}

TcpAcceptor::~TcpAcceptor() {
  Close();
}

void TcpAcceptor::Close() {
  uv_close(uv_handle(ptr()), nullptr);
}
