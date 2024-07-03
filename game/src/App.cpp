// Local Headers
#include "../include/App.hpp"

std::shared_ptr<SDL_Renderer> App::renderer = nullptr;

App::App() { 
    std::clog << "App created!\n";
}

App::~App() {
    SDL_Quit();
    TTF_Quit();
    std::clog << "SDL quitted...\n";
    std::clog << "App destroyed!\n"; 
}

void App::init(const std::string& title, const int& x, const int& y, const int& width, const int& height, const unsigned int& flags) {
    // Init all SDL shit or it won't work
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0 && TTF_Init() == 0) { // App needs SDL initialized to do anything
        std::clog << "SDL initialized...\n";
        window_ = std::shared_ptr<SDL_Window>(SDL_CreateWindow(title.c_str(), x, y, width, height, flags), SDL_DestroyWindow);

        font_ = std::shared_ptr<TTF_Font>(TTF_OpenFont("./fonts/Helvetica-Bold.ttf", 20), TTF_CloseFont);

        if(window_.get()) { // App needs a window_ to create renderer
            std::clog << "Window created...\n"; 
            renderer = std::shared_ptr<SDL_Renderer>(SDL_CreateRenderer(window_.get(), 1, 0), SDL_DestroyRenderer);

            if(renderer.get()) { // App needs a renderer to display anything
                std::clog << "Renderer created...\n";
                
                isRunning_ = true;
                std::clog << "Shoot the swarm is running!!!\n";
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
    SDL_RenderClear(renderer.get());      // Clear renderer to show new things on screen

    // >>> Add stuff to render here <<<

    SDL_SetRenderDrawColor(renderer.get(), 0, 0, 0 ,0);   // invisible color to stop renderer from drawing
    SDL_RenderPresent(renderer.get());                    // Show everything on screen
}
