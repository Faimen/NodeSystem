//
// Created by Faimen on 24.09.2024.
//

#include <iostream>
#include <utility>
#include "Node.h"
#include "Events/SumHandler.h"
#include "RandomNode.h"
#include "Network.h"

namespace NodeSystem {
    void Node::subscribe(Node *neighbor, std::shared_ptr<EventHandler> handler) {
        if (neighbor != this && !subscribers.count(neighbor)) {
            subscribers[neighbor] = std::move(handler);
        }
    }

    void Node::unsubscribe(Node *neighbor) {
        auto it = subscribers.find(neighbor);
        if (it != subscribers.end()) {
            subscribers.erase(it);
        }
    }

    void Node::notify(int data) {
        for (auto & subscriber : subscribers) {
            Node* neighbor = subscriber.first;
            std::shared_ptr<EventHandler> handler = subscriber.second;
            handler->handleEvent(data, name, neighbor->getName());
        }
    }

    void Node::createAndSubscribeNewNode() {
        std::string newNodeName = Network::generateUniqueNodeName();
        auto newNode = std::make_shared<RandomNode>(newNodeName, newNodesBuffer);

        newNodesBuffer.push_back(newNode);

        this->subscribe(newNode.get(), std::make_shared<SumHandler>());

        std::cout << name << " created new node and subscribed: " << newNodeName << std::endl;
    }
} // NodeSystem