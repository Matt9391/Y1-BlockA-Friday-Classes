//// Template, 2024 IGAD Edition
//// Get the latest version from: https://github.com/jbikker/tmpl8
//// IGAD/NHTV/BUAS/UU - Jacco Bikker - 2006-2024
//
#include "precomp.h"
//#include "game.h"
//
//// -----------------------------------------------------------
//// Friday Class 04/09/2026
//// 
////Try this:
////	Surface s("assets/nc2tiles.png");
////	s.CopyTo(screen, 0, 0);
//// 
////	Between those lines:
////	Easy:
////		divide every pixel of the image by 65536.
////	Intermediate:
////		half the intensity of each pixel.
////	Hard: 
////		smoothly fade the image in and out
//// -----------------------------------------------------------
//
//void Game::Init()
//{
//
//}
//
//float brightness = 0.f;
//float dir = 1.f;
//
//// -----------------------------------------------------------
//// Main application tick function - Executed once per frame
//// -----------------------------------------------------------
//void Game::Tick(float /* deltaTime */)
//{
//
//	// Easy assignment
//	//Surface s("assets/nc2tiles.png");
//
//	//for (int i = 0, y = 0; y < s.height; y++) {
//	//	for (int x = 0; x < s.width; x++, i++) {
//	//		s.pixels[i] /= 66536;
//	//	}
//	//}
//
//	//s.CopyTo(screen, 0, 0);
//
//	//// Intermediate assignment
//	//Surface s("assets/nc2tiles.png");
//
//	//for (int i = 0, y = 0; y < s.height; y++) {
//	//	for (int x = 0; x < s.width; x++, i++) {
//	//		uint p = s.pixels[i];
//
//	//		uint r = ((p >> 16) & 0xFF) / 2;
//	//		uint g = ((p >> 8) & 0xFF) / 2;
//	//		uint b = ((p) & 0xFF) / 2;
//
//	//		s.pixels[i] = 0xFF000000 | r << 16 | g << 8 | b;
//	//	}
//	//}
//
//	//s.CopyTo(screen, 0, 0);
//
//	// Hard assignment
//	Surface s("assets/nc2tiles.png");
//
//	//[01234567, 01234567, 01234567, 01234567]
//
//	for (int i = 0, y = 0; y < s.height; y++) {
//		for (int x = 0; x < s.width; x++, i++) {
//
//			uint p = s.pixels[i];
//
//			uint r = ((p >> 16) & 0xFF) * brightness;
//			uint g = ((p >> 8) & 0xFF) * brightness;
//			uint b = ((p) & 0xFF) * brightness;
//
//			s.pixels[i] = 0xFF000000 | r << 16 | g << 8 | b;
//		}
//	}
//
//	s.CopyTo(screen, 0, 0);
//
//
//	brightness += 0.01f * dir;
//
//	if (brightness >= 1.f || brightness <= 0.005f) {
//		dir *= -1.f;
//	}
//
//}