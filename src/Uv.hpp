// Copyright 2017 <ggarber@github>

#ifndef SRC_UV_HPP_
#define SRC_UV_HPP_

#include <uv.h>

namespace uvcpp {

  void uv_guard(int res);
  uv_handle_t* uv_handle(void* handle);

}

#endif  // SRC_UV_HPP_
