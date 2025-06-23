#ifndef PALMTREE_HPP
#define PALMTREE_HPP

#include "Rocket.hpp"
#include <vector>

// Palmtree class inherits from Rocket
class Palmtree : public Rocket {
public:
    void Trigger(std::vector<Rocket*>& v) override;  // Override Trigger method
    void Draw() override;  // Override Draw method
};

#endif
