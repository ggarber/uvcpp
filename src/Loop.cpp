// Copyright 2016 <ggarber@github>

#include "Loop.hpp"

#include <uv.h>

#include <iostream>

using uvcpp::Loop;

Loop::Loop(): loop_(new uv_loop_t, [](uv_loop_t *loop) { uv_loop_close(loop); delete loop; }) {
  // Testing valgrind works
  // new uv_loop_t();
  uv_loop_init(loop_.get());
}

void Loop::run() const {
  std::cout << "Hola world!\n";
}
