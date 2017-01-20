// Copyright 2016 <ggarber@github>

#ifndef TEMPLATE_H
#define TEMPLATE_H

#include <memory>

typedef struct uv_loop_s uv_loop_t;

namespace bootstrap {

class Loop {
 public:
  Loop();

 public:
  void run() const;

 private:
  std::unique_ptr<uv_loop_t, void(*)(uv_loop_t*)> loop_;
};

}  // namespace bootstrap

#endif  // TEMPLATE_H
