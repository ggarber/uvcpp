// Copyright 2017 <ggarber@github>

#include "Loop.hpp"

int main(int argc, char *argv[]) {
    uvcpp::Loop loop;

    auto udp = loop.udp();
    udp->Listen(6868);
    loop.Run();

    return 0;
}
