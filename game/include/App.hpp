#pragma once
#define SDL_MAIN_HANDLED

// Local headers
#include "./Game.hpp"
#include "./MainMenu.hpp"
#include "./Settings.hpp"

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

    // Enum class with all application modes
    enum class Mode { MainMenu = 0, Game = 1, Settings = 2 };
    void setMode(Mode newMode); 

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
    Mode currentMode_;
    std::unique_ptr<AppMode> mode;

    // Gameplay variables
    

    // Text variables
    std::shared_ptr<TTF_Font> font_ = std::shared_ptr<TTF_Font>(TTF_OpenFont("./fonts/Helvetica-Bold.ttf", 20), TTF_CloseFont);
    SDL_Color textColor_ = {255, 255, 255}; // white
};