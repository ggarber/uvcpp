// Copyright 2017 <ggarber@github>

#include "Loop.hpp"

#include <uv.h>
#include <spdlog/spdlog.h>

#include <iostream>

#include "Uv.hpp"

using uvcpp::Loop;
using uvcpp::UdpSocket;
using uvcpp::TcpSocket;
using uvcpp::TcpAcceptor;

Loop::Loop(): loop_(new uv_loop_t, [](auto loop) { delete loop; }) {
  uv_loop_init(ptr());
}

Loop::~Loop() {
  Close();
}

void Loop::Run() {
  spdlog::get("uvcpp")->info("Loop::begin");

  uvcpp::uv_guard(uv_run(ptr(), UV_RUN_DEFAULT));

  spdlog::get("uvcpp")->info("Loop::end");
}

void Loop::Close() {
  uv_loop_close(ptr());
}

void Loop::Stop() {
  uv_stop(ptr());
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
