#pragma once

#include "Vector.h"
#include "Ray.h"
#include <vector> 

class Particle {
private:
	Vector pos;
	std::vector<Ray> rays;

public:
	Particle();
	Particle(int fov);
	Particle(int x, int y);
	Particle(int x, int y, int fov);
	void update(float x, float y);
	void show(SDL_Renderer* renderer);
	void pointRaysAt(float angle);

	//Returns float representing distance of closest Boundary hit
	std::vector<float> castRays(SDL_Renderer* renderer, std::vector<Boundary> walls);
};