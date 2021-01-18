#pragma once

#include "Vector.h"
#include "Boundary.h"
#include "C:\Program Files\SDL2\SDL2-2.0.12\include\SDL.h"

class Ray {
private:
	Vector pos;
	Vector dir;

	//Helper functions to pointRayAt(angle);
	void setAngle(float degrees);

public:
	Ray(Vector position, float angle);
	void lookAt(int x, int y);
	void pointRayAt(float angle);

	void show(SDL_Renderer* renderer);
	void drawRay(SDL_Renderer* renderer, float x, float y);
	void set(float x, float y);
	float getxdir();
	float getydir();

	Vector getpos();
	Vector cast(SDL_Renderer* renderer, Boundary wall);

};