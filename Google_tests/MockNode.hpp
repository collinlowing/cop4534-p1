//
// Created by cel on 7/15/22.
//

#ifndef COP4534_P1_MOCKNODE_HPP
#define COP4534_P1_MOCKNODE_HPP

#include "gmock/gmock.h"
#include "../StringNode.hpp"

class MockNode : public StringNode {
public:
    MOCK_METHOD(std::size_t, hash, (), (override));
};


#endif //COP4534_P1_MOCKNODE_HPP
