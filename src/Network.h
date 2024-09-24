//
// Created by Faimen on 24.09.2024.
//

#ifndef NODESYSTEM_NETWORK_H
#define NODESYSTEM_NETWORK_H

#include <vector>
#include <memory>
#include <random>
#include "Node.h"

namespace NodeSystem {

    class Network {
        std::vector<std::shared_ptr<Node>> nodes;
        std::vector<std::shared_ptr<Node>> newNodesBuffer;
        std::random_device rd;
        std::mt19937 gen;

        static int uniqueNodeCounter;
    public:
        Network() : gen(rd()) {}

        void addNode(const std::shared_ptr<Node> &node);

        void updateNetwork();

        void generateRandomSubscriptions();

        void generateRandomNetwork(int numNodes);

        bool isNetworkAlive() const {
            return !nodes.empty();
        }

        static std::string generateUniqueNodeName() {
            return "Node" + std::to_string(uniqueNodeCounter++);
        }
    };

} // NodeSystem

#endif //NODESYSTEM_NETWORK_H
