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



// Create Ball class with params and methods
class Ball
{
// define public params
public:
    float Ball_pos_x, Ball_pos_y;
    int Ball_speed_x, Ball_speed_y;
    int Ball_radius;
    
    // define public method for drawing ball
    void Draw()
    {
        DrawCircle(Ball_pos_x, Ball_pos_y, Ball_radius, WHITE);
    }
    
    // define the update method
    void Update()
    {
        Ball_pos_x += Ball_speed_x;
        Ball_pos_y += Ball_speed_y;
        
        if (Ball_pos_y + Ball_radius >= GetScreenHeight() || Ball_pos_y - Ball_radius <=0)
        {
            Ball_speed_y *= -1;
        }
    }
};


// Create Paddle class with params and methods
class Paddle
{
// define public params
public:
    float Paddle_pos_x, Paddle_pos_y;
    float Paddle_width, Paddle_height;
    int Paddle_speed;
    
    // define public method for drawing ball
    void Draw()
    {
        DrawRectangle(Paddle_pos_x, Paddle_pos_y, Paddle_width, Paddle_height, LIGHTGRAY);
    }
    
    // define the update method
    // This method allows to have change on an object ased on user input
    void Update()
    {
        if (IsKeyDown(KEY_UP)) {
            Paddle_pos_y = Paddle_pos_y - Paddle_speed;
        }
        if (IsKeyDown(KEY_DOWN)) {
            Paddle_pos_y = Paddle_pos_y + Paddle_speed;
        }
        
        if (Paddle_pos_y <= 0)
        {
            Paddle_pos_y = 0;
            
        }
        if (Paddle_pos_y + Paddle_height >= GetScreenHeight())
        {
            Paddle_pos_y = GetScreenHeight() - Paddle_height;
        }
    }
};


// Create a CPUPaddle class that is enheiting from the Paddle class all of the params and methods
// we can overrdode the methods if we want by re-defining it inside the class
class CPUPaddle : public Paddle
{
public:
    void Update()
    {
        
    }
    
};

// instantiate ball object
Ball ball;

// instantiate players objects
Paddle player_1;

CPUPaddle player_2;



int main () {
    
    // Game globals
    const int Screen_Width  = 1300;
    const int Screen_Height = 900;
    SetTargetFPS(60);
    
    // init window
    InitWindow(Screen_Width, Screen_Height, "GR_PONG");
    
    // Objects constructors
    // Ball constructor
    ball.Ball_radius    = 10;
    ball.Ball_pos_x     = Screen_Width/2;
    ball.Ball_pos_y     = Screen_Height/2;
    ball.Ball_speed_x   = 7;
    ball.Ball_speed_y   = 7;
    
    // Players constructors
    player_1.Paddle_pos_x   = 20;
    player_1.Paddle_pos_y   = Screen_Height/2 - 60;
    player_1.Paddle_width   = 10;
    player_1.Paddle_height  = 120;
    player_1.Paddle_speed   = 20;
    
    player_2.Paddle_pos_x   = Screen_Width - 30;
    player_2.Paddle_pos_y   = Screen_Height/2 - 60;
    player_2.Paddle_width   = 10;
    player_2.Paddle_height  = 120;
    player_2.Paddle_speed   = 20;
    
    
    
    // Game loop where all the checks and events happen
    // While statement to define the close state while is not closed, run -->
    // function WindowShouldClose() operates with an Escape key or Close button on window
    while (WindowShouldClose() == false) {
        BeginDrawing();
        
        // Updating elements
        // This needs to be called before the draw to start the update
        ball.Update();
        player_1.Update();
            
        
        // Drawing
        // before the drawing we need to fill the canvas to blask to delate what was previosuly drawn
        ClearBackground(BLACK);
        
        
        // Drawing elements
        // middle line to separate the players
        DrawLine(Screen_Width/2, 0, Screen_Width/2, Screen_Height, DARKGRAY);
        
        // ball draw method call
        ball.Draw();
        
        // players draw method call
        player_1.Draw();
        player_2.Draw();
//        DrawRectangle(Screen_Width - 30, Screen_Height/2 - 60, 10, 120, LIGHTGRAY);
        
        EndDrawing();
    }
    
    
    // close window
    CloseWindow();
    return 0;
}
