#include "raylib.h"
#define RAYGUI_IMPLEMENTATION
#include "Ball.h"
#include "raygui.h"


const int screenWidth = 1200;
const int screenHeight = 800;
auto bgColor = ORANGE;

void DrawContent(Vector2 position, Vector2 scroll) {
    GuiButton((Rectangle){position.x + 20 + scroll.x, position.y + 50 + scroll.y, 100, 25}, "Button 1");
    GuiButton((Rectangle){position.x + 20 + scroll.x, position.y + 100 + scroll.y, 100, 25}, "Button 2");
    GuiButton((Rectangle){position.x + 20 + scroll.x, position.y + 150 + scroll.y, 100, 25}, "Button 3");
    GuiLabel((Rectangle){position.x + 20 + scroll.x, position.y + 200 + scroll.y, 250, 25}, "A Label");
    GuiLabel((Rectangle){position.x + 20 + scroll.x, position.y + 250 + scroll.y, 250, 25}, "Another Label");
    GuiLabel((Rectangle){position.x + 20 + scroll.x, position.y + 300 + scroll.y, 250, 25}, "Yet Another Label");
}


int main() {
    // Possible window flags
    /*
    FLAG_VSYNC_HINT
    FLAG_FULLSCREEN_MODE    -> not working properly -> wrong scaling!
    FLAG_WINDOW_RESIZABLE
    FLAG_WINDOW_UNDECORATED
    FLAG_WINDOW_TRANSPARENT
    FLAG_WINDOW_HIDDEN
    FLAG_WINDOW_MINIMIZED   -> Not supported on window creation
    FLAG_WINDOW_MAXIMIZED   -> Not supported on window creation
    FLAG_WINDOW_UNFOCUSED
    FLAG_WINDOW_TOPMOST
    FLAG_WINDOW_HIGHDPI     -> errors after minimize-resize, fb size is recalculated
    FLAG_WINDOW_ALWAYS_RUN
    FLAG_MSAA_4X_HINT
    */
    // set anti-aliasing
    //SetConfigFlags(FLAG_WINDOW_HIDDEN);
    SetConfigFlags(FLAG_MSAA_4X_HINT);
    InitWindow(screenWidth, screenHeight, "raylib [shapes] example - clock of clocks");

    SetTargetFPS(60);

    bool buttonPressed = false;
    Ball myBall(400.0f, 225.0f, 5.0f, 4.0f, 60.0f, MAROON);


    // Main game loop
    while (!WindowShouldClose()) {
        DrawContent((Vector2){140, 320}, {100.0f, 0.0f});

        // Render an immediate-mode button widget using raygui
        if (GuiButton((Rectangle){600, 400, 200, 50}, "Click Me!")) {
            buttonPressed = !buttonPressed;
        }

        if (buttonPressed) {
            int result = GuiMessageBox((Rectangle){screenWidth / 2, screenHeight / 2, 250, 100},
                                       "#191#Message Box", "Hi! This is a message!", "Nice;Cool");
            if (result >= 0) buttonPressed = false;
        }
        myBall.Update();

        BeginDrawing();
        ClearBackground(bgColor);
        DrawFPS(10, 10);
        myBall.Draw();
        EndDrawing();
    }


    CloseWindow(); // Close window and OpenGL context


    return 0;
}
