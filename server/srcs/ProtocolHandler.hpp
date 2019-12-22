//
// Created by spynight on 12/22/19.
//

#ifndef R_TYPE_PROTOCOLHANDLER_H
#define R_TYPE_PROTOCOLHANDLER_H

#include <string>

namespace rtype {
    class ProtocolHandler {
        public:
            static std::string handleMessageReceived(const std::string &messageReceived);
    };
}


#endif //R_TYPE_PROTOCOLHANDLER_H
