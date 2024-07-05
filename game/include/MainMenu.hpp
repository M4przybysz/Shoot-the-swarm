#pragma once 

// Local Headers
#include "./AppMode.hpp"

// Class mostly responsible for main menu buttons (redirecting to other App modes) and looking good (or not) when player opens the game 
class MainMenu : public AppMode {
 public:
    void handleEvents(SDL_Event event) override;
    void update(const double& deltaTime) override;
    void render() override;
};
