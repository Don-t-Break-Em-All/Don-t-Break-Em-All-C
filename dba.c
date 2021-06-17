#include "raylib.h"

int main(void) {
    const int screenWidth = 320;
    const int screenHeight = 200;

    InitWindow(screenWidth, screenHeight, "Don't Break 'Em All");

    Vector2 playerPosition = { (float)screenWidth/2, (float)screenHeight/2 };

    SetTargetFPS(60); 

    Texture2D player = LoadTexture("assets/character1.png");              

    while (!WindowShouldClose()) {
        if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) playerPosition.x += 2.0f;
        if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) playerPosition.x -= 2.0f;
        if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) playerPosition.y -= 2.0f;
        if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) playerPosition.y += 2.0f;

        BeginDrawing();

            ClearBackground(BLACK);

            DrawTexture(player, playerPosition.x, playerPosition.y, WHITE);

        EndDrawing();
    }

    CloseWindow();        
    

    return 0;
}
