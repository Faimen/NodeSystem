//
// Created by Faimen on 24.09.2024.
//

#ifndef NODESYSTEM_RANDOMNODE_H
#define NODESYSTEM_RANDOMNODE_H

#include <random>
#include "Node.h"

namespace NodeSystem {

    class RandomNode : public Node {
        std::random_device rd;
        std::mt19937 gen;
        std::uniform_int_distribution<> dis;

    public:
        RandomNode(const std::string &name, std::vector<std::shared_ptr<Node>> &buffer)
                : Node(name, buffer), gen(rd()), dis(1, 100) {}

        int generateEvent() override;

        void update() override;
    };

} // NodeSystem

#endif //NODESYSTEM_RANDOMNODE_H
