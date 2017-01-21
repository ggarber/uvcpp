// Copyright 2016 <ggarber@github>

#ifndef SRC_LOOP_HPP_
#define SRC_LOOP_HPP_

#include <memory>

typedef struct uv_loop_s uv_loop_t;

namespace uvcpp {

class Loop {
 public:
  Loop();

 public:
  void run() const;

 private:
  std::unique_ptr<uv_loop_t, void(*)(uv_loop_t*)> loop_;
};

}  // namespace bootstrap

#endif  // SRC_LOOP_HPP_
