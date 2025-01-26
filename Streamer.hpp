#include "Rocket.hpp"

class Streamer : public Rocket {
  public:
    virtual void Trigger(std::vector<Rocket*>& v);  // Override Trigger
};
