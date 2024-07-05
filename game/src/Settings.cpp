// Local Headers
#include "../include/App.hpp"
#include "../include/Settings.hpp"

// SDL Headers
#include <SDL2/SDL.h>

// C++ Headers
#include <iostream>


void Settings::handleEvents(SDL_Event event) {
    switch (event.type) {
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym) {
                case SDLK_1:
                    App::getInstance().setMode(App::Mode::MainMenu);
                    break;
                case SDLK_2:
                    App::getInstance().setMode(App::Mode::Game);
                    break;
                default:
                    break;
            }
            break;
        default:
            break;
    }
}

void Settings::update(const double& deltaTime) {

}

void Settings::render() {
    SDL_SetRenderDrawColor(App::getInstance().renderer.get(), 0, 0, 255, 255);
}
