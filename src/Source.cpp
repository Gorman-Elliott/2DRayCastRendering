

#include "C:\Program Files\SDL2\SDL2-2.0.12\include\SDL.h"
#include "Boundary.h"
#include "Ray.h"
#include "Vector.h"
#include "Particle.h"
#include "Player.h"
#include "Camera.h"

#include <cstdlib>
#include <time.h>
#include <vector>
#include <iostream>

int main(int args, char* argv[]) {
	//init random seed
	srand(time(NULL));

	if (SDL_Init(SDL_INIT_VIDEO) == 0) {
		SDL_Window* window = NULL;
		SDL_Renderer* renderer = NULL;
		SDL_Texture* texture;

		texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 1280, 480);

		//int SDL_CaptureMouse(SDL_bool enabled);
		//Boundary wall(rand() & 640, rand() & 480, rand() & 640, rand() & 480);
		int mouseX = 0;
		int mouseY = 0;
		std::vector<Boundary> walls;
		walls.push_back(Boundary(50, 50, 300, 50));
		walls.push_back(Boundary(50, 50, 300, 50));
		walls.push_back(Boundary(300, 50, 300, 125));
		walls.push_back(Boundary(300, 125, 400, 125));
		walls.push_back(Boundary(400, 125, 400, 225));
		walls.push_back(Boundary(250, 225, 400, 225));
		walls.push_back(Boundary(300, 225, 300, 300));
		walls.push_back(Boundary(175, 225, 225, 225));
		walls.push_back(Boundary(175, 225, 175, 300));
		walls.push_back(Boundary(50, 300, 300, 300));
		walls.push_back(Boundary(50, 50, 50, 300));


		Camera camera(60);
		Player player(camera, 325, 200);


		if (SDL_CreateWindowAndRenderer(1280, 480, 0, &window, &renderer) == 0) {
			SDL_bool done = SDL_FALSE;

			while (!done) {
				SDL_Event event;

				//render the walls
				SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_TRANSPARENT);
				for (Boundary wall : walls) {
					wall.show(renderer);
				}



				SDL_RenderPresent(renderer);
				while (SDL_PollEvent(&event)) {
					if (event.type == SDL_QUIT) {
						done = SDL_TRUE;
						SDL_DestroyRenderer(renderer);
						SDL_Quit();
					}

					if ((event.type == SDL_MOUSEMOTION) && SDL_BUTTON(SDL_BUTTON_LEFT)) {
						mouseX = event.motion.x;
						mouseY = event.motion.y;
					}

					if (event.type == SDL_MOUSEMOTION) {
						switch (event.motion.xrel) {
							case(1):
								player.panView(renderer, texture, walls, -5);
								break;
							case(-1):
								player.panView(renderer, texture, walls, 5);
								break;
						}
					}

					if (event.type == SDL_KEYDOWN) {

						if (event.key.keysym.sym == SDL_KeyCode(SDLK_d)) {
							player.moveDir(renderer, texture, walls, PLAYER_DIR::RIGHT, 2);
						} else if (event.key.keysym.sym == SDL_KeyCode(SDLK_w)) {
							player.moveDir(renderer, texture, walls, PLAYER_DIR::FORWARD, 2);
						} else if (event.key.keysym.sym == SDL_KeyCode(SDLK_s)) {
							player.moveDir(renderer, texture, walls, PLAYER_DIR::BACKWARD, 2);
						}
						else if (event.key.keysym.sym == SDL_KeyCode(SDLK_a)) {
							player.moveDir(renderer, texture, walls, PLAYER_DIR::LEFT, 2);
						}
						else if (event.key.keysym.sym == SDL_KeyCode(SDLK_e)) {
							//camera.pointCameraAt(10);
							//ray.pointRayAt(5);
							//particle.pointRaysAt(5);
							//particle.castRays(renderer, walls);
							//player.panView(renderer, texture, walls, -5);
						}
						else if (event.key.keysym.sym == SDL_KeyCode(SDLK_q)) {
							//player.panView(renderer, texture, walls, 5);
						}
					}
				}
			}
		
		}



		for (Boundary wall : walls) {
			wall.~Boundary();
		}

		if (renderer) {
			SDL_DestroyRenderer(renderer);
		}
		if (window) {
			SDL_DestroyWindow(window);
		}

	}

	return 0;
}





