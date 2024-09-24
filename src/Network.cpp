//
// Created by Faimen on 24.09.2024.
//

#include <iostream>
#include "Network.h"
#include "Events/SumHandler.h"
#include "Events/CountHandler.h"
#include "RandomNode.h"

namespace NodeSystem {
    int Network::uniqueNodeCounter = 0;

    void Network::addNode(const std::shared_ptr<Node> &node) {
        if (std::find(nodes.begin(), nodes.end(), node) == nodes.end()) {
            nodes.push_back(node);
        } else {
            std::cerr << "Node already exists!" << std::endl;
        }
    }

    void Network::updateNetwork() {
        std::cout << "   Starting network update..." << std::endl;

        std::vector<std::shared_ptr<Node>> toBeRemoved;

        for (auto &node : nodes) {
            node->update();
        }

        for (auto &node : nodes) {
            if (node->hasNoSubscribers()) {
                toBeRemoved.push_back(node);
            }
        }

        for (auto &node : toBeRemoved) {
            for (auto &neighbor : nodes) {
                if (neighbor.get() != node.get()) {
                    neighbor->unsubscribe(node.get());
                }
            }
        }

        for (auto &node : toBeRemoved) {
            std::cout << "Removing node: " << node->getName() << std::endl;
            nodes.erase(std::remove(nodes.begin(), nodes.end(), node), nodes.end());
        }

        if (!newNodesBuffer.empty()) {
            nodes.insert(nodes.end(), newNodesBuffer.begin(), newNodesBuffer.end());
            newNodesBuffer.clear();
        }

        std::cout << "   Network update completed." << std::endl;
    }

    void Network::generateRandomSubscriptions() {
        std::uniform_int_distribution<size_t> dist(0, nodes.size() - 1);
        std::uniform_int_distribution<size_t> handlerDist(0, 1);

        for (auto &node: nodes) {
            size_t numSubscriptions = dist(gen) % 3;

            for (int i = 0; i < numSubscriptions; ++i) {
                size_t neighborIdx = dist(gen);

                if (nodes[neighborIdx].get() != node.get()) {
                    std::shared_ptr<EventHandler> handler;
                    if (handlerDist(gen) == 0) {
                        handler = std::make_shared<SumHandler>();
                    } else {
                        handler = std::make_shared<CountHandler>();
                    }
                    node->subscribe(nodes[neighborIdx].get(), handler);
                }
            }
        }
    }

    void Network::generateRandomNetwork(int numNodes) {
        for (int i = 0; i < numNodes; ++i) {
            auto node = std::make_shared<RandomNode>(Network::generateUniqueNodeName(), newNodesBuffer);
            addNode(node);
        }
        generateRandomSubscriptions();
    }
} // NodeSystem