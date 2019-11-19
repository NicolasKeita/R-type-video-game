
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include "ClientWrapper.hpp"

std::string handleMessageReceived(const std::string &messageReceived)
{
    return "";
}

int main()
{
    uti::network::ClientWrapper client;
    try {
        client.connectToHost("0.0.0.0", 42424, &handleMessageReceived);
        client.sendMessage("Salut");
        std::cerr << "[DEBUG] Debut de la loop" << std::endl;

        while (true) {
            usleep(100000);
            std::thread t([&](){ client._io_context.run(); });
            std::cerr << "[DEBUG] One loop done" << std::endl;
            t.join();
        }
    }
    catch (std::exception &e) {
        std::cerr << "[DEBUG]" << e.what() << std::endl;
    }
    return 0;
}