#pragma once

// SDL Headers
#include <SDL2/SDL.h>

// Virtual class that is a blueprint for all App modes
// App modes: MainMenu, Game, Settings
class AppMode {
 public:
    virtual ~AppMode() {}
    virtual void handleEvents(SDL_Event event) = 0;
    virtual void update(const double& deltaTime) = 0;
    virtual void render() = 0;
};
