#pragma once

// Local headers

// SDL Headers
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

// C++ Headers
#include <array>
#include <iostream>
#include <memory>
#include <string>

class App {
 public:
    App();
    ~App();

    // Basicaly return self?
    static App& getInstance() {
        static App instance;
        return instance;
    }

    void init(const std::string& title, const int& x, const int& y, const int& width, const int& height, const unsigned int& flags);
    bool isRunning() { return isRunning_; };
    
    void handleEvents();
    void update(const double& deltaTime);
    void render();

    static std::shared_ptr<SDL_Renderer> renderer;

 private:
    bool isRunning_ = false;
    std::shared_ptr<SDL_Window> window_;

    // Gameplay variables
    

    // Text variables
    std::shared_ptr<TTF_Font> font_;
    SDL_Color textColor_ = {255, 255, 255}; // white
};