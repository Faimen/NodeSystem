//
// Created by Faimen on 24.09.2024.
//

#ifndef NODESYSTEM_NODE_H
#define NODESYSTEM_NODE_H

#include <unordered_map>
#include "Events/EventHandler.h"

namespace NodeSystem {

    class Node {
    protected:
        std::string name;
        std::unordered_map<Node *, std::shared_ptr<EventHandler>> subscribers;
        std::vector<std::shared_ptr<Node>> &newNodesBuffer;

    public:
        Node(std::string nodeName, std::vector<std::shared_ptr<Node>> &buffer)
                : name(std::move(nodeName)), newNodesBuffer(buffer) {}

        virtual void update() = 0;

        virtual int generateEvent() = 0;

        void subscribe(Node *neighbor, std::shared_ptr<EventHandler> handler);

        void unsubscribe(Node *neighbor);

        void notify(int data);

        const std::string &getName() const {
            return name;
        }

        bool hasNoSubscribers() const {
            return subscribers.empty();
        }

        void createAndSubscribeNewNode();

        virtual ~Node() = default;
    };

} // NodeSystem

#endif //NODESYSTEM_NODE_H
