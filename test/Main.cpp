// Copyright 2016 <ggarber@github>

#include <gtest/gtest.h>
#include <spdlog/spdlog.h>

int main(int argc, char *argv[]) {
  spdlog::stdout_logger_mt("uvcpp");

  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
