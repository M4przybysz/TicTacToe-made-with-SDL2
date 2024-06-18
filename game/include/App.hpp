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

    static SDL_Renderer* renderer;

 private:
    bool isRunning_ = false;
    SDL_Window* window_;
    TTF_Font* font_;

    // Gameplay variables
    bool player_ = 1; // 1 = X, 0 = O 
    int turnCounter_ = 1;
    std::array<std::array<char, 3>, 3> board_ {{{'.', '.', '.'},
                                               {'.', '.', '.'},
                                               {'.', '.', '.'}}};

    // Text variables
    std::string playerInfo_;
    std::string turnNum_; 
    SDL_Surface* playerInfoSurface_;
    SDL_Surface* turnNumSurface_;
    SDL_Color textColor_ = {255, 255, 255}; // white
    SDL_Texture* playerInfoTexture_;
    SDL_Texture* turnNumTexture_;
};
