// Copyright 2016 <ggarber@github>

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
  close();
}

void TcpSocket::close() {
  uv_close(uv_handle(ptr()), nullptr);
}

TcpAcceptor::TcpAcceptor(Loop* loop) {
  uv_guard(uv_tcp_init(loop->ptr(), &socket_));
}

TcpAcceptor::~TcpAcceptor() {
  close();
}

void TcpAcceptor::close() {
  uv_close(uv_handle(ptr()), nullptr);
}
