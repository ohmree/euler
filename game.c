/*******************************************************************************************
*
* im trying to make a game fml
*
********************************************************************************************/

#include "raylib.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

//#define PLATFORM_WEB
#define DEBUG

#if defined(PLATFORM_WEB)
    #include <emscripten/emscripten.h>
#endif

//----------------------------------------------------------------------------------
// Some Defines
//----------------------------------------------------------------------------------

#define PLAYER_MAX_LIFE         5

//----------------------------------------------------------------------------------
// Types and Structures Definition
//----------------------------------------------------------------------------------
typedef enum GameScreen { LOGO, TITLE, GAMEPLAY, ENDING } GameScreen;

typedef struct Player {
    Vector2 position;
    Vector2 size;
    int life;
} Player;

typedef struct Food {
    Vector2 position;
    float   radius;
    int value;
} Food;

//----------------------------------------------------------------------------------
// Global Variables Definition
//----------------------------------------------------------------------------------
static int  screenWidth = 800;
static int  screenHeight = 450;

static int  framesCounter;
static bool gameOver;
static bool pause;

static int  foodAmount = 0;

static int  timer = 0;

#if defined(DEBUG)
static char* debugText;
#endif

static Player player;

static Food food1;
static Food food2;
static Food food3;

//------------------------------------------------------------------------------------
// Module Functions Declaration (local)
//------------------------------------------------------------------------------------
static void InitGame(void);         // Initialize game
static void UpdateGame(void);       // Update game (one frame)
static void DrawGame(void);         // Draw game (one frame)
static void UnloadGame(void);       // Unload game
static void UpdateDrawFrame(void);  // Update and Draw (one frame)


// Additional module functions
static void UpdateFood(void);

//----------------------------------------------------------------------------------
// Main Enry Point
//----------------------------------------------------------------------------------
int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    InitWindow(screenWidth, screenHeight, "what should i name this piece of s##t game");
    
    InitGame();
    
#if defined(PLATFORM_WEB)
    emscripten_set_main_loop(UpdateDrawFrame, 0, 1);
#else
    
    SetTargetFPS(60);   // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------
    
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        UpdateGame();
        //----------------------------------------------------------------------------------
        
        // Draw
        //----------------------------------------------------------------------------------
        DrawGame();
        //----------------------------------------------------------------------------------
        
    }
#endif

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadGame();         // Unload loaded data (textures, sounds, models etc)
    
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

//----------------------------------------------------------------------------------
// Module Functions Definition
//----------------------------------------------------------------------------------
void InitGame(void)
{
    // Initialize player
    player.position = (Vector2){ screenWidth/2, screenHeight - screenHeight/8 };
    player.size = (Vector2){ screenWidth/10, screenHeight/22.5 };
    player.life = PLAYER_MAX_LIFE;
#if defined(debug)
    debugText = malloc(sizeof(char) * 40);
#endif
}

// Update game (one frame)
void UpdateGame(void)
{
    if (!gameOver)
    {
        if (IsKeyPressed('P')) pause = !pause;
        
        if (!pause)
        {
            // Player Movement
            if (IsKeyDown(KEY_LEFT))                                  player.position.x -= 5;
            if ((player.position.x - player.size.x/2) <= 0)           player.position.x =  player.size.x/2;
            if (IsKeyDown(KEY_RIGHT))                                 player.position.x += 5;
            if ((player.position.x + player.size.x/2) >= screenWidth) player.position.x =  screenWidth - player.size.x/2;
            
        #if defined(DEBUG)
            // Debug text
            debugText = FormatText("screen: %dx%d\nx: %f\ny: %f\nfood: %d", screenWidth, screenHeight, player.position.x, player.position.y, foodAmount);
        #endif
            // Update food
            Timer(UpdateFood, 5);
            
            if (player.life <= 0) gameOver = true;
        }
    }
    else
    {
        if (IsKeyPressed(KEY_ENTER))
        {
            InitGame();
            gameOver = false;
        }
    }
}

// Draw game (one frame)
void DrawGame(void)
{
    BeginDrawing();
        ClearBackground(RAYWHITE);
        
        if (!gameOver)
        {
        #if defined(DEBUG)
            DrawText(debugText, 50, 70, 20, BLACK);
        #endif
            // Draw ground
            DrawRectangle(0, screenHeight - screenHeight/8 + (screenHeight - screenHeight/8)/36, screenWidth, screenHeight/9, GREEN);
            
            // Draw player bar
            DrawRectangle(player.position.x - player.size.x/2, player.position.y - player.size.y/2, player.size.x, player.size.y, BLACK);
            
            // Draw player lives
            for (int i = 0; i < player.life; i++) DrawRectangle(20 + 40*i, screenHeight - 30, 35, 10, LIGHTGRAY);
       
            if (pause) DrawText("GAME PAUSED", screenWidth / 2 - MeasureText("GAME PAUSED", 40)/2, screenHeight/2 - 40, 40, GRAY);
        }
        else DrawText("PRESS [ENTER] TO PLAY AGAIN", screenWidth/2 - MeasureText("PRESS [ENTER] TO PLAY AGAIN", 20)/2, screenHeight/2 - 50, 20, GRAY);
        
    EndDrawing();
}

// Unload game variables
void UnloadGame(void)
{
    free(debugText);
}

// Update and draw (one frame)
void UpdateDrawFrame(void)
{
    UpdateGame();
    DrawGame();
}    

//--------------------------------------------------------------------------------------
// Additional module functions
//--------------------------------------------------------------------------------------
static void UpdateFood(void)
{
    if (foodAmount < 3) foodAmount++;
    
    // Draw food
    for (int i = 1; i <= foodAmount; i++)
    {
        if (timer == 20)
        {
            timer = 0;
            DrawCircle(20*i, player.position.y, 50, RED);
        }
        else timer++;
    }
}

static void Timer(void (*func)(void), int seconds)
{
    clock_t startTime = clock();
    if ((startTime - clock() / CLOCKS_PER_SEC) > seconds) (*func)();
}