#pragma once

// Local Headers
#include "./AppMode.hpp"

// Class responsible for playing the actual game
//! May be separated into: deck builder, offline campaign and online matches
class Game : public AppMode {
 public:
    void handleEvents(SDL_Event event) override;
    void update(const double& deltaTime) override;
    void render() override;
};
