#pragma once

#include "raylib.h"

class Ball {
private:
    Vector2 position;
    Vector2 speed;
    float radius;
    Color color;

public:
    // Constructor to initialize variables
    Ball(float x, float y, float speedX, float speedY, float r, Color c) {
        position = { x, y };
        speed = { speedX, speedY };
        radius = r;
        color = c;
    }

    // Update logic (movement and collision)
    void Update() {
        position.x += speed.x;
        position.y += speed.y;

        // Bounce off screen walls
        if ((position.x >= (GetScreenWidth() - radius)) || (position.x <= radius)) {
            speed.x *= -1.0f;
        }
        if ((position.y >= (GetScreenHeight() - radius)) || (position.y <= radius)) {
            speed.y *= -1.0f;
        }
    }

    // Render logic (drawing)
    void Draw() const {
        DrawCircleV(position, radius, color);
    }
};
