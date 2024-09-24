//
// Created by Faimen on 24.09.2024.
//

#ifndef NODESYSTEM_EVENTHANDLER_H
#define NODESYSTEM_EVENTHANDLER_H

#include <string>

namespace NodeSystem {

    class EventHandler {
    public:
        virtual void handleEvent(int data, const std::string &sender, const std::string &receiver) = 0;

        virtual ~EventHandler() = default;
    };

} // NodeSystem

#endif //NODESYSTEM_EVENTHANDLER_H
