// Copyright 2017 <ggarber@github>

#ifndef SRC_BUFFER_HPP_
#define SRC_BUFFER_HPP_

#include <array>

namespace uvcpp {

struct Buffer {
  std::array<uint8_t, 1500> data;
};

}  // namespace uvcpp

#endif  // SRC_BUFFER_HPP_
