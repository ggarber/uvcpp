// Copyright 2017 <ggarber@github>

#ifndef SRC_LOOP_HPP_
#define SRC_LOOP_HPP_

#include <memory>

#include "Udp.hpp"
#include "Tcp.hpp"

typedef struct uv_loop_s uv_loop_t;

namespace uvcpp {

class UdpSocket;
class TcpSocket;
class TcpAcceptor;

class Loop {
 public:
  Loop();
  virtual ~Loop();

 public:
  void Run();
  void Stop();
  void Close();

  std::unique_ptr<uvcpp::UdpSocket> udp();
  std::unique_ptr<uvcpp::TcpSocket> tcp();
  std::unique_ptr<uvcpp::TcpAcceptor> acceptor();
  // std::unique_ptr<uvcpp::Timer> timer();

  // std::unique_ptr<uvcpp::Timer> timeout(
  //   std::function<void(const T&)> action, uint64_t timeout);

  // std::unique_ptr<uvcpp::Timer> interval(
  //   std::function<void(const T&)> action, uint64_t interval);

  uv_loop_t* ptr() { return loop_.get(); }

 private:
  std::unique_ptr<uv_loop_t, void(*)(uv_loop_t*)> loop_;
};

}  // namespace uvcpp

#endif  // SRC_LOOP_HPP_
