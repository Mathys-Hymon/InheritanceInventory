#include "raylib.h"
#include <iostream>

void Start();
void Update();
void Draw();
void Unload();

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
    //InitWindow(1000, 850, "brick breaker");
    //SetTargetFPS(60);


}

void Update()
{
}

void Draw()
{
  /*  BeginDrawing();
    ClearBackground(BLUE);
    EndDrawing();*/
}

void Unload()
{
    //CloseWindow();
}
