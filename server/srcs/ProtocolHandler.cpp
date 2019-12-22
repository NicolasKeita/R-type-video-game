//
// Created by spynight on 12/22/19.
//

#include <boost/algorithm/string/predicate.hpp>
#include <iostream>
#include "GameInfo.hpp"
#include "ProtocolHandler.hpp"

std::string rtype::ProtocolHandler::handleMessageReceived(const std::string &messageReceived)
{
    static int i = 1;
    static rtype::GameInfo gameInfo;

    try {
        if (boost::starts_with(messageReceived, "IDREQUEST")) {
            return "ID " + std::to_string(i++);
        }
        if (boost::starts_with(messageReceived, "POS ")) {
            gameInfo.savePosition(messageReceived);
            return gameInfo.allPositionInOneString();
        }
        if (boost::starts_with(messageReceived, "TERMINATE")) {
            exit(84);
        }
    } catch (std::invalid_argument &e) {
        std::cerr << "[Rtype server] wrong arg to stoi" << std::endl;
    }
    return messageReceived;
}
