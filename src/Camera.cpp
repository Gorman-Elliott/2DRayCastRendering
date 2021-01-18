

#include "Camera.h"
#include <iostream>

Camera::Camera() {
	origin.set(640, 0);
	pos.set(0, 0);
	particle = Particle();
}

Camera::Camera(int fov) {
	origin.set(640, 0);
	pos.set(0, 0);
	particle = Particle(fov);
}

//where param x, y are the coords of 
// particle start pos, generally used for character start pos
Camera::Camera(int x, int y) {
	origin.set(640, 0);
	pos.set(x, y);
	particle = Particle(x, y);
}

//where param x, y are the coords of 
// particle start pos, generally used for character start pos
Camera::Camera(int x, int y, int fov) {
	origin.set(640, 0);
	pos.set(x, y);
	particle = Particle(x, y, fov);
}

void Camera::updateCameraPos(int x, int y) {
	pos.set(x, y);
}

void Camera::updateCameraPos(Vector newPos) {
	pos.set(newPos.getx(), newPos.gety(), newPos.getz());
}

void Camera::pointCameraAt(float angle) {
	particle.pointRaysAt(angle);
}

void Camera::updateView(SDL_Renderer* renderer, SDL_Texture* texture, std::vector<Boundary> walls) {
	particle.update(pos.getx(), pos.gety());
	scene = particle.castRays(renderer, walls);

	Camera::drawView(renderer, texture, walls);
	scene.clear();
}

void Camera::drawView(SDL_Renderer* renderer, SDL_Texture* texture, std::vector<Boundary> walls) {
	//draw rects from camera origin to end of screen
	float dw;

	if (scene.size() == 0) {
		dw = 640 / 1;
	}
	else {
		dw = 640 / scene.size();
	}

	for (int i = scene.size() - 1; i >= 0; i--) {
		float d = scene[i];
		float b = Camera::map(d, 0, 480, 255, 0);
		float h = Camera::map(d, 0, 640, 480, 0);

		SDL_Rect rect;
		rect.x = (((scene.size()-i) * dw) + (dw / 2)) + 640;
		rect.y = 480 - h;
		rect.w = dw;

		// TODO Adjust height of rectangle to make rendering better
		rect.h = h - rect.y;
		
		//if (rect.h < 320) {
		//	rect.h = h + rect.y;
		//}


		//Set draw color as a range, b
		SDL_SetRenderDrawColor(renderer, b, b, b, SDL_ALPHA_TRANSPARENT);

		SDL_SetRenderTarget(renderer, texture);
		//SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0x00);
		SDL_RenderDrawRect(renderer, &rect);
		SDL_RenderFillRect(renderer, &rect);
		SDL_SetRenderTarget(renderer, NULL);

	}
}

float Camera::map(float value, float istart, float istop, float ostart, float ostop) {
	return ostart + (ostop - ostart) * ((value - istart) / (istop - istart));
}

