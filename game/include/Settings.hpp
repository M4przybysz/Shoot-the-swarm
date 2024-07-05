#pragma once

// Local Headers
#include "./AppMode.hpp"

// Class responsible for handling key bindings, graphic settings and other stuff to be set
class Settings : public AppMode {
 public:
    void handleEvents(SDL_Event event) override;
    void update(const double& deltaTime) override;
    void render() override;
};
