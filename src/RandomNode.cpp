//
// Created by Faimen on 24.09.2024.
//

#include "RandomNode.h"

namespace NodeSystem {
    void RandomNode::update() {
        if(hasNoSubscribers()) return;

        int eventData = generateEvent();
        notify(eventData);

        std::uniform_int_distribution<> chance(0, 4);
        if (chance(gen) == 0) {
            createAndSubscribeNewNode();
        }
    }

    int RandomNode::generateEvent() {
        return dis(gen);
    }
} // NodeSystem