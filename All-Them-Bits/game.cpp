// Template, 2024 IGAD Edition
// Get the latest version from: https://github.com/jbikker/tmpl8
// IGAD/NHTV/BUAS/UU - Jacco Bikker - 2006-2024

#include "precomp.h"
#include "game.h"

// -----------------------------------------------------------
// Friday Class 04/09/2026
// 
//ALL TOGETHER NOW - ~1 HOUR ASSIGNMENT
//Create an application where sand drops from the top of the screen(e.g.
//	from a random position).Sand can be red, green or blue.Behaviour:
//Red: down if no ‘red’ below, diagonally down if no red in that direction.
//Green and blue : same as red.Or : Harder : (only)blue can move horizontally
//until blocked(so : it keeps its direction until blocked or dropping).
//Red and green will ‘stack’.Blue(when doing the ‘harder’ part) will form a
//puddle.
//Red, green and blue sand can occupy the same pixel.They only look for
//their own colour.Their colours can thus blend.
//Updating a particle : 1. Remove from current pixel; 2. Update position; 3. Place at new pixel.
//All done ? Make the particle struct as small as possible.Harder : Test if it
//can be faster when not as small as possible.
// -----------------------------------------------------------

struct Particle {
	int x, y;
	uint clr;
	bool alive;

	Particle(int x, int y, int clrNum) {
		this->x = x;
		this->y = y;
		this->alive = true;
		switch (clrNum)
		{
			case 0:
				this->clr = 0xFFff0000;
				break;
			case 1:
				this->clr = 0xFF00ff00;
				break;
			case 2:
				this->clr = 0xFF0000ff;
				break;
		default:
			break;
		}
	}
};

void Game::Init()
{

}

std::vector<Particle> particles;

// -----------------------------------------------------------
// Main application tick function - Executed once per frame
// -----------------------------------------------------------
void Game::Tick(float /* deltaTime */)
{
	screen->Clear(0xFF000000);
	//particles.push_back(Particle(rand() % screen->width, 0, rand() % 3));
	particles.push_back(Particle(200, 0, 2));
	particles.push_back(Particle(300, 0, 1));
	particles.push_back(Particle(250, 0, 0));
	particles.push_back(Particle(180, 50, 2));

	for (Particle& p : particles) {

		screen->Plot(p.x, p.y, p.clr);

	}

	for (Particle& p : particles)
{
    if (!p.alive) continue;

    // Blue behaviour
    if (p.clr == 0xFF0000FF)
    {
        // Check if directly below is blue
        bool blueBelow = false;

        if (p.y + 1 < screen->height)
        {
            uint below = screen->pixels[(p.y + 1) * screen->width + p.x];
            blueBelow = (below == 0xFF0000FF);
        }

        if (blueBelow)
        {
            // Try moving left or right
            int direction = (rand() % 2 == 0) ? -1 : 1;
            int newX = p.x + direction;

            // Make sure we stay inside the screen
            if (newX >= 0 && newX < screen->width)
            {
                uint sidePixel =
                    screen->pixels[p.y * screen->width + newX];

                // Move sideways if there isn't blue there
                if (sidePixel != 0xFF0000FF)
                {
                    p.x = newX;
                }
            }
        }
        else
        {
            // Nothing blue below, so fall
            p.y++;
        }
    }
    else
    {
        // Red and green simply fall
        if (p.y + 1 < screen->height)
        {
            uint below =
                screen->pixels[(p.y + 1) * screen->width + p.x];

            if (below != p.clr)
            {
                p.y++;
            }
            else
            {
                p.alive = false;
            }
        }
    }

    // Remove particles that reach the bottom
    if (p.y >= screen->height - 1)
    {
        p.alive = false;
    }
}
}