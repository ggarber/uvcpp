// Copyright 2016 <ggarber@github>

#include "Uv.hpp"

#include <exception>
#include <iostream>

void uvcpp::uv_guard(int res) {
  if (res < 0) {
    printf("Error %d", res);
    throw std::exception();
  }
}

uv_handle_t* uvcpp::uv_handle(void* handle) {
  return reinterpret_cast<uv_handle_t*>(handle);
}
