// Template, 2024 IGAD Edition
// Get the latest version from: https://github.com/jbikker/tmpl8
// IGAD/NHTV/BUAS/UU - Jacco Bikker - 2006-2024

#include "precomp.h"
#include "game.h"

// -----------------------------------------------------------
// Friday Class 04/09/2026
// 
////Try this:
//	Surface s("assets/nc2tiles.png");
//	s.CopyTo(screen, 0, 0);
//	This time:
//	Easy:
//		Remove green and blue from the image.
//	Intermediate:
//		Keep only red for pixel 0, only green for
//		pixel 1, only blue for pixel 2, repeat.
//	Hard:
//		load a second image and smoothly
//		cross - fade between the two.
// -----------------------------------------------------------

void Game::Init()
{

}

float brightness = 0.f;
float brightness2 = 1.f;
float dir = 1.f;

// -----------------------------------------------------------
// Main application tick function - Executed once per frame
// -----------------------------------------------------------
void Game::Tick( float /* deltaTime */ )
{
	// Easy assignment

	//Surface s("assets/nc2tiles.png");
	//
	//for (int i = 0, y = 0; y < s.height; y++) {
	//	for (int x = 0; x < s.width; x++, i++) {
	//		s.pixels[i] = s.pixels[i] & 0xFFFF0000;
	//	}
	//}

	//s.CopyTo(screen, 0, 0);

	// Intermediate assignment
	//Surface s("assets/nc2tiles.png");

	//for (int i = 0, y = 0; y < s.height; y++) {
	//	for (int x = 0; x < s.width; x++, i++) {
	//		int color = i % 3;

	//		switch (color) {
	//			case 0:
	//				s.pixels[i] = s.pixels[i] & 0xFFFF0000;
	//				break;
	//			case 1:
	//				s.pixels[i] = s.pixels[i] & 0xFF00FF00;
	//				break;
	//			case 2:
	//				s.pixels[i] = s.pixels[i] & 0xFF0000FF;
	//				break;

	//		}
	//	}
	//}

	//s.CopyTo(screen, 0, 0);

	// Hard assignment

	Surface s("assets/nc2tiles.png");
	Surface s2("assets/ball.png");

	for (int i = 0, y = 0; y < s.height; y++) {
		for (int x = 0; x < s.width; x++, i++) {
		
			uint p = s.pixels[i];
		
			uint r = ((p >> 16) & 0xFF) * brightness;
			uint g = ((p >> 8) & 0xFF) * brightness;
			uint b = ((p) & 0xFF) * brightness;
		
			s.pixels[i] = 0xFF000000 | r << 16 | g << 8 | b;
		}
	}
		
	s.CopyTo(screen, 0, 0);
	
	for (int i = 0, y = 0; y < s2.height; y++) {
		for (int x = 0; x < s2.width; x++, i++) {

			uint p = s2.pixels[i];

			uint r = ((p >> 16) & 0xFF) * brightness2;
			uint g = ((p >> 8) & 0xFF) * brightness2;
			uint b = ((p) & 0xFF) * brightness2;

			s2.pixels[i] = 0xFF000000 | r << 16 | g << 8 | b;
		}
	}

	s2.CopyTo(screen, 0, 0);

		
	brightness += 0.01f * dir;
	brightness2 -= 0.01f * dir;
		
	if (brightness >= 1.f || brightness <= 0.005f) {
		dir *= -1.f;
	}
}