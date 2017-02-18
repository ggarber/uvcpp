// Copyright 2017 <ggarber@github>

#include "Loop.hpp"

#include <uv.h>
#include <spdlog/spdlog.h>

#include <iostream>

using uvcpp::Loop;
using uvcpp::UdpSocket;
using uvcpp::TcpSocket;
using uvcpp::TcpAcceptor;

Loop::Loop(): loop_(new uv_loop_t, [](uv_loop_t *loop) { uv_loop_close(loop); delete loop; }) {
  uv_loop_init(ptr());
}

void Loop::run() {
  spdlog::get("uvcpp")->info("Loop::begin");

  int res = uv_run(ptr(), UV_RUN_DEFAULT);

  spdlog::get("uvcpp")->info("Loop::end");
}

std::unique_ptr<UdpSocket> Loop::udp() {
  return std::make_unique<UdpSocket>(this);
}

std::unique_ptr<TcpSocket> Loop::tcp() {
  return std::make_unique<TcpSocket>(this);
}

std::unique_ptr<TcpAcceptor> Loop::acceptor() {
  return std::make_unique<TcpAcceptor>(this);
}
