//
// Created by Faimen on 24.09.2024.
//

#ifndef NODESYSTEM_COUNTHANDLER_H
#define NODESYSTEM_COUNTHANDLER_H

#include "EventHandler.h"

namespace NodeSystem {

    class CountHandler : public EventHandler {
        int count = 0;
    public:
        void handleEvent(int data, const std::string &sender, const std::string &receiver) override;
    };

} // NodeSystem

#endif //NODESYSTEM_COUNTHANDLER_H
