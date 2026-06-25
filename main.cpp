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
    Color yellow = {243, 216, 63, 255};
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
        DrawRectangleRoundedLinesEx({10, 10, 780, 780}, 0.18f, 20, 2, yellow);
        //DrawRectangleRoundedLinesEx Added in raylib 5.5
        //DrawRectangleRoundedLines({10, 10, 780, 780}, 0.18f, 20, 2, yellow); //Use this for previous raylib versions
        DrawLineEx({25, 730}, {775, 730}, 3, yellow);

        DrawFPS(10, 10);
        EndDrawing();
    }

    CloseWindow(); // Close window and OpenGL context

    return 0;
}
