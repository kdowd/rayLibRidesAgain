#include "raylib.h"
#include "raymath.h"
#define RAYGUI_IMPLEMENTATION
#include "Button.h"
#include "raygui.h"

#include <iostream>

using namespace std;

const int screenWidth = 1200;
const int screenHeight = 800;
auto bgColor = ORANGE;

int main() {
    cout << "GO" << endl;
    SetConfigFlags(FLAG_MSAA_4X_HINT);
    InitWindow(screenWidth, screenHeight, "raylib [shapes] example - clock of clocks");
    SetTargetFPS(30);

    Texture2D texture = LoadTexture("../resources/background.png");
    Button startButton{"../resources/start_button.png", {400, 400}, 0.25};


    // Main game loop

    while (!WindowShouldClose()) {
        bool mousePressed = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
        
        BeginDrawing();
        ClearBackground(bgColor);
        Vector2 mousePos = GetMousePosition();
        DrawTexture(texture, 0, 0, WHITE);
        startButton.DrawButton();
        if (startButton.isPressed(mousePos, mousePressed)) {
            cout << mousePos.x << " " << mousePos.y << endl;
        };
        DrawFPS(10, 10);
        EndDrawing();
    }

    CloseWindow(); // Close window and OpenGL context

    return 0;
}
