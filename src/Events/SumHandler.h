//
// Created by Faimen on 24.09.2024.
//

#ifndef NODESYSTEM_SUMHANDLER_H
#define NODESYSTEM_SUMHANDLER_H

#include "EventHandler.h"

namespace NodeSystem {

    class SumHandler : public EventHandler {
        int sum = 0;
    public:
        void handleEvent(int data, const std::string &sender, const std::string &receiver) override;
    };

} // NodeSystem

#endif //NODESYSTEM_SUMHANDLER_H
