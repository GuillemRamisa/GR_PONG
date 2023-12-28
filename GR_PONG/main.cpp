//
//  main.cpp
//  GR_PONG
//
//  Created by Guillem Ramisa de Soto on 28/12/23.
//  Based on https://github.com/educ8s/Raylib-CPP-Starter-Template-for-VSCODE
//
// required linked Frameworks/files for compilation
// - libraylib.a
// - OpenGL
// - CoreVideos
// - IOkit
// - Cocoa


#include <iostream>
#include "raylib.h"

using namespace std;

int main () {
    
    // Game globals
    const int Screen_Width = 1280;
    const int Screen_Height = 820;
    SetTargetFPS(60);
    
    // init window
    InitWindow(Screen_Width, Screen_Height, "GR_PONG");
    
    // Game loop where all the checks and events happen
    // While statement to define the close state while is not closed, run -->
    // function WindowShouldClose() operates with an Escape key or Close button on window
    while (WindowShouldClose() == false) {
        BeginDrawing();
        
        EndDrawing();
    }
    
    
    // close window
    CloseWindow();
    return 0;
}
