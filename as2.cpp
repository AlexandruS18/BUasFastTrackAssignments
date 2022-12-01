#include "game.h"
#include "surface.h"
#include <cstdint>

// colors yay
#define RED 0xff0000
#define GREEN 0x00ff00
#define BLUE 0x0000ff
#define YELLOW 0xffff00

// typedefing to make it more readable but it may as well be useless?
typedef std::uint16_t coord;
typedef std::uint32_t color;


namespace Tmpl8
{
    // storing all variables used in the Line function as a struct type
    struct BonusArray
    {
        coord x1;
        coord y1;
        coord x2;
        coord y2;
        color clr;
    };
    // initializing the array
    BonusArray array[14] = {};
    // -----------------------------------------------------------
    // Initialize the application
    // -----------------------------------------------------------
    void Game::Init()
    {
        // storing each line from the paper one by one in the array
        // letter C
        array[0] = { 120, 240, 180, 240, RED };
        array[1] = { 120, 240, 120, 480, RED };
        array[2] = { 120, 480, 180, 480, RED };
        // letter O
        array[3] = { 240, 240, 300, 240, GREEN };
        array[4] = { 240, 240, 240, 480, GREEN };
        array[5] = { 300, 240, 300, 480, GREEN };
        array[6] = { 240, 480, 300, 480, GREEN };
        // letter D
        array[7] = { 360, 480, 420, 480, BLUE };
        array[8] = { 360, 240, 360, 480, BLUE };
        array[9] = { 360, 240, 420, 480, BLUE };
        // letter E
        array[10] = { 480, 240, 600, 240, YELLOW };
        array[11] = { 480, 240, 480, 480, YELLOW };
        array[12] = { 480, 480, 600, 480, YELLOW };
        array[13] = { 480, 360, 600, 360, YELLOW };
    }

    void Game::Shutdown()
    {
    }

    static Sprite rotatingGun(new Surface("assets/aagun.tga"), 36);
    static int frame = 0;

    // Main tick function
    void Game::Tick(float deltaTime)
    {
        // clear the graphics window
        screen->Clear(0);
        // loop through all the elements of the array to draw them
        for (auto i : array) // I use auto for the variable i because the struct type name could be modified
        {
            screen->Line(i.x1, i.y1, i.x2, i.y2, i.clr);
        }
    }
}