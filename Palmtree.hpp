#include "Rocket.hpp"

class Palmtree : public Rocket {
  public:
    virtual void Trigger(std::vector<Rocket*>& v);  // Override Trigger
};
