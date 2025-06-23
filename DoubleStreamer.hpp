#pragma once
#include "Streamer.hpp"

class DoubleStreamer : public Streamer {
public:
    void Trigger(std::vector<Rocket *> &v) override;
};
