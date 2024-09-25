#include "raylib.h"
#include <iostream>
#include "GameManager.h"

GameManager mGameManager;

void Start();
void Update();
void Draw();
void Unload();

int main() {
    Start();

    while (!WindowShouldClose() && !mGameManager.GameShouldClose()) {

        Update();
        Draw();
    }

    Unload();
    return 0;
}

void Start()
{
    InitWindow(1000, 850, "brick breaker");
    SetTargetFPS(60);
    mGameManager = GameManager();
    mGameManager.Load();
}

void Update()
{
    mGameManager.Update();
}

void Draw()
{
    BeginDrawing();
    mGameManager.Draw();
    ClearBackground(BLUE);
    EndDrawing();
}

void Unload()
{
    CloseWindow();
    mGameManager.Unload();
}
