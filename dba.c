#include "dba.h"

#define OPT_WIDTH       220       // Max width for the options container
#define MARGIN_SIZE       8       // Size for the margins

int main(void) {
    const int screenWidth = 320;
    const int screenHeight = 200;

    InitWindow(screenWidth, screenHeight, "Don't Break 'Em All");

    Vector2 playerPosition = { (float)screenWidth/2, (float)screenHeight/2 };
    Vector2 tilesetPosition = { (float)screenWidth/2, (float)screenHeight/2 };

    SetTargetFPS(60); 

    Texture2D player = LoadTexture("assets/character.png");             
    Texture2D tileset = LoadTexture("assets/tileset.png");

    const Rectangle tiles[] = {
        (Rectangle){ 1, 1, 16, 16 },
        (Rectangle){ 75, 3, 100, 100 },
        (Rectangle){ 3, 75, 66, 66 },
        (Rectangle){ 7, 156, 50, 50 },
        (Rectangle){ 85, 106, 90, 45 },
        (Rectangle){ 75, 154, 100, 60}
    }; 

    float scale = 1.0f, rotation = 0.0f;

    while (!WindowShouldClose()) {
       // if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) pslayerPosition.x += 2.0f;
        if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) playerPosition.x -= 2.0f;
        if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) playerPosition.y -= 2.0f;

        if (!collidesBottom(playerPosition, tilesetPosition)) playerPosition.y ++;
        if (!collidesRight(playerPosition, tilesetPosition) && (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D))) playerPosition.x += 2.0f;
        BeginDrawing();

            ClearBackground(BLACK);

            DrawTexture(player, playerPosition.x, playerPosition.y, WHITE);

            DrawTextureTiled(tileset, tiles[0], (Rectangle){(float)OPT_WIDTH+MARGIN_SIZE, (float)MARGIN_SIZE, screenWidth - OPT_WIDTH - 2.0f*MARGIN_SIZE, screenHeight - 2.0f*MARGIN_SIZE},
                tilesetPosition, rotation, scale, WHITE);
        EndDrawing();
    }

    CloseWindow();        
    

    return 0;
}
