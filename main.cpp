#include "raylib.h"
#include "GameManager.h"
#include <iostream>

void Start();
void Update();
void Draw();
void Unload();

GameManager gm = GameManager();

int main() {
    Start();

    while (!WindowShouldClose()) {

        Update();
        Draw();
    }

    Unload();
    return 0;
}

void Start()
{
    InitWindow(1080, 720, "Inventory System");
    SetTargetFPS(60);
    gm.Load();
}

void Update()
{
    gm.Update();
}

void Draw()
{
    BeginDrawing();
    ClearBackground(BLUE);
    gm.Draw();
    EndDrawing();
}

void Unload()
{
    gm.Unload();
    CloseWindow();
}
