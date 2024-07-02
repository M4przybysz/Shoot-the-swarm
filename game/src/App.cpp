// Local Headers
#include "../include/App.hpp"

SDL_Renderer* App::renderer = nullptr;

App::App() { 
    std::clog << "App created!\n";
}

App::~App() { 
    TTF_CloseFont(font_);
    std::clog << "Font closed...\n";

    SDL_DestroyWindow(window_);
    std::clog << "Window destroyed...\n";
    SDL_DestroyRenderer(renderer);
    std::clog << "Renderer destroyed...\n";
    SDL_Quit();
    TTF_Quit();
    std::clog << "SDL quitted...\n";
    std::clog << "App destroyed!\n"; 
}

void App::init(const std::string& title, const int& x, const int& y, const int& width, const int& height, const unsigned int& flags) {
    // Init all SDL shit or it won't work
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0 && TTF_Init() == 0) { // App needs SDL initialized to do anything
        std::clog << "SDL initialized...\n";
        window_ = SDL_CreateWindow(title.c_str(), x, y, width, height, flags);

        font_ = TTF_OpenFont("./fonts/Helvetica-Bold.ttf", 20);

        if(window_) { // App needs a window_ to create renderer
            std::clog << "Window created...\n"; 
            renderer = SDL_CreateRenderer(window_, 1, 0);

            if(renderer) { // App needs a renderer to display anything
                std::clog << "Renderer created...\n";
                
                isRunning_ = true;
                std::clog << "Just Tic-Tac-Toe is running!!!\n";
            }
            else { std::cerr << "Couldn't create a renderer!\n"; }
        }
        else { std::cerr << "Couldn't create a window!\n"; }
    }
    else {
        std::cerr << "Couldn't initialize SDL!\n";
        isRunning_ = false;
    }
}

void App::handleEvents() {
    SDL_Event event; // variable to store events

    while(SDL_PollEvent(&event)) { // get new event
        switch(event.type) {
            case SDL_QUIT:
                isRunning_ = false;
                std::clog << "Window closed...\n";
                break;
            
            // >>>Add more events to be handled here<<<
    

            default:
                break;
        }
    }
}

void App::update(const double& deltaTime) {
}

void App::render() {
    SDL_RenderClear(renderer);      // Clear renderer to show new things on screen

    // >>> Add stuff to render here <<<

    SDL_SetRenderDrawColor(renderer, 0, 0, 0 ,0);   // invisible color to stop renderer from drawing
    SDL_RenderPresent(renderer);                    // Show everything on screen
}
