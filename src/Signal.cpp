// Copyright 2016 <ggarber@github>

#include "Signal.hpp"

#include <iostream>

using uvcpp::Signal;

void Signal::run() const {
  std::cout << "Hello world!\n";
}

int Signal::sum(int a, int b) const {
  return a + b;
}
