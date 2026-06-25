#pragma once
#include <iostream>
#include <ostream>
#include <string>
#include "raylib.h"

class Button {
public:
    Vector2 position;
    Texture2D texture;

    Button(const char *imagePath, Vector2 pos, float scale = 1.0f) : position(pos) {
        Image image = LoadImage(imagePath);

        int originalWidth = image.width;
        int originalHeight = image.height;

        int newWidth = static_cast<int>(originalWidth * scale);
        int newHeight = static_cast<int>(originalHeight * scale);

        ImageResize(&image, newWidth, newHeight);
        texture = LoadTextureFromImage(image);
        UnloadImage(image);
    }

    bool isPressed(Vector2 mousePos, bool mousePressed) {
        Rectangle rect = {
            position.x, position.y, static_cast<float>(texture.width), static_cast<float>(texture.height)
        };

        if (mousePressed) {
            return true;
        }

        return false;
    }

    void DrawButton() const { DrawTextureV(texture, position, WHITE); }

    ~Button() { UnloadTexture(texture); }
};
