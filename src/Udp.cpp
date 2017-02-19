// Copyright 2017 <ggarber@github>

#include "Udp.hpp"

#include <spdlog/spdlog.h>

#include <exception>
#include <iostream>

#include "Uv.hpp"
#include "Loop.hpp"
#include "Buffer.hpp"

using uvcpp::Loop;
using uvcpp::UdpSocket;
using uvcpp::Buffer;
using uvcpp::uv_handle;

static void uv_guard(int res) {
  if (res < 0) {
    printf("Error %d %s", res, uv_strerror(res));
    throw std::exception();
  }
}

class SendData {
 public:
  SendData() { req.data = this; }
  uv_udp_send_t req;
};

void on_alloc(uv_handle_t* handle, size_t suggested_size, uv_buf_t* buf) {
  buf->base = reinterpret_cast<char*>(malloc(suggested_size));
  buf->len = suggested_size;
}

void on_recv(uv_udp_t* handle,
             ssize_t nread,
             const uv_buf_t* buf,
             const struct sockaddr* addr,
             unsigned flags) {
  if (nread == -1) {
    uv_close(uv_handle(handle), NULL);
    free(buf->base);
    return;
  }

  spdlog::get("uvcpp")->info("UdpSocket::on_recv");

  auto socket = reinterpret_cast<UdpSocket*>(handle->data);
  Buffer buffer;
  ::memcpy(buffer.data.data(), buf->base, nread);
  socket->Data(buffer);

  free(buf->base);
}

void on_send(uv_udp_send_t *req, int status) {
  spdlog::get("uvcpp")->info("UdpSocket::on_send {}", uv_strerror(status));

  auto wrap = reinterpret_cast<SendData*>(req->data);
  delete wrap;
  if (status < 0) {
    return;
  }
}

UdpSocket::UdpSocket(Loop* loop) {
  SPDLOG_DEBUG(spdlog::get("uvcpp"), "UdpSocket:");

  uv_guard(uv_udp_init(loop->ptr(), &socket_));
  socket_.data = this;
}

void UdpSocket::listen() {
  listen(0);
}

UdpSocket::~UdpSocket() {
  close();
}

void UdpSocket::listen(ushort port) {
  struct sockaddr_in addr;
  uv_guard(uv_ip4_addr("0.0.0.0", port, &addr));

  uv_guard(uv_udp_bind(&socket_, (const struct sockaddr*) &addr, 0));

  uv_guard(uv_udp_recv_start(&socket_, on_alloc, on_recv));
}

void UdpSocket::close() {
  if (!uv_is_closing(uv_handle(ptr()))) {
    uv_close(uv_handle(&socket_), nullptr);
  }
}

void UdpSocket::send(const Buffer& data) {
  SPDLOG_DEBUG(spdlog::get("uvcpp"), "UdpSocket::send");

  struct sockaddr_in addr;
  uv_guard(uv_ip4_addr("127.0.0.1", 6868, &addr));

  auto wrap = new SendData();
  uv_buf_t buffer;
  on_alloc(uv_handle(ptr()), 256, &buffer);
  uv_guard(uv_udp_send(&wrap->req, ptr(), &buffer, 1, (const struct sockaddr*) &addr, on_send));
}
