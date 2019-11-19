
#include <iostream>
#include "ClientWrapper.hpp"

std::string handleMessageReceived(const std::string &messageReceived)
{
    return "";
}

int main()
{
    uti::network::ClientWrapper client;
    try {
        auto welcomeMessage = client.connectToHost("0.0.0.0", 42424, &handleMessageReceived);
        while (true) {
        }
    }
    catch (std::exception &e) {
        std::cerr << "[DEBUG]" << e.what() << std::endl;
    }
    return 0;
}