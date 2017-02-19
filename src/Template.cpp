// Copyright 2017 <ggarber@github>

#include "Template.hpp"

#include <iostream>

using uvcpp::Template;

void Template::Run() const {
  std::cout << "Hello world!\n";
}

int Template::Sum(int a, int b) const {
  return a + b;
}
