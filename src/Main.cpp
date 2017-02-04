// Copyright 2016 <ggarber@github>

#include "Loop.hpp"

int main(int argc, char *argv[]) {
    uvcpp::Loop loop;

    auto udp = loop.udp();
    udp->listen(6868);
    loop.run();

    return 0;
}
