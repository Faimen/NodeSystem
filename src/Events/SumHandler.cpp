//
// Created by Faimen on 24.09.2024.
//

#include <iostream>
#include "SumHandler.h"

namespace NodeSystem {
    void SumHandler::handleEvent(int data, const std::string &sender, const std::string &receiver) {
        sum += data;
        std::cout << sender << " -> " << receiver << ": S = " << sum << std::endl;
    }
} // NodeSystem