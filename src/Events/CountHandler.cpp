//
// Created by Faimen on 24.09.2024.
//

#include <iostream>
#include "CountHandler.h"

namespace NodeSystem {
    void CountHandler::handleEvent(int data, const std::string &sender, const std::string &receiver) {
        count++;
        std::cout << sender << " -> " << receiver << ": N = " << count << std::endl;
    }
} // NodeSystem