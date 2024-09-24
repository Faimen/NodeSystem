#include <iostream>
#include "Network.h"

int main() {
    NodeSystem::Network network;

    int numNodes;
    std::cout << "Enter number of nodes: ";
    std::cin >> numNodes;
    network.generateRandomNetwork(numNodes);

    while (network.isNetworkAlive()) {
        network.updateNetwork();
    }

    std::cout << "Network terminated." << std::endl;
    return 0;
}
