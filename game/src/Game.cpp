// Local Headers
#include "../include/App.hpp"
#include "../include/Game.hpp"

// SDL Headers
#include <SDL2/SDL.h>

// C++ Headers
#include <iostream>

void Game::handleEvents(SDL_Event event) {
    switch (event.type) {
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym) {
                case SDLK_1:
                    App::getInstance().setMode(App::Mode::MainMenu);
                    break;
                case SDLK_3:
                    App::getInstance().setMode(App::Mode::Settings);
                    break;
                default:
                    break;
            }
            break;
        default:
            break;
    }
}

void Game::update(const double& deltaTime) {

}

void Game::render() {
    SDL_SetRenderDrawColor(App::getInstance().renderer.get(), 0, 255, 0, 255);
}
