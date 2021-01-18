
#include "Particle.h"
#include <iostream>

Particle::Particle() {
	pos.set(0, 0);
	rays = std::vector<Ray>();
	for (int a = 0; a <= 60; a += 1) {
		rays.push_back(Ray(pos, a));
	}
}

Particle::Particle(int fov) {
	pos.set(0, 0);
	rays = std::vector<Ray>();
	for (int a = 0; a <= fov; a += 1) {
		rays.push_back(Ray(pos, a));
	}
}

Particle::Particle(int x, int y) {
	pos.set(x, y);
	//rays.push_back(Ray(pos, 90));
	rays = std::vector<Ray>();
	for (int a = 0; a <= 60; a += 2) {
		rays.push_back(Ray(pos, a));
	}
}

Particle::Particle(int x, int y, int fov) {
	pos.set(x, y);
	//rays.push_back(Ray(pos, 90));
	rays = std::vector<Ray>();
	for (int a = 0; a <= fov; a += 2) {
		rays.push_back(Ray(pos, a));
	}
}

//pointed rays are offset from <0
void Particle::pointRaysAt(float angle) {
	for (auto& ray : rays) {
		ray.pointRayAt(angle);
	}
}


void Particle::update(float x, float y) {
	pos.set(x, y);
}

void Particle::show(SDL_Renderer* renderer) {
	//draw self and then rays casted from self
	SDL_RenderDrawPoint(renderer, pos.getx(), pos.gety());

	// This code is unecessary once the rays are casted using castRays();
	for (auto& ray : rays) {
		//ray.set(pos.getx(), pos.gety());
		//ray.pointRayAt(45);
		ray.show(renderer);
	}
}

std::vector<float> Particle::castRays(SDL_Renderer* renderer, std::vector<Boundary> walls) {
	std::vector<float> distances;

	for (auto& ray : rays) {
		ray.set(pos.getx(), pos.gety());
		Vector castedRay;
		Vector shortestRay;
		float shortestDistance = 3000;

		for (Boundary wall : walls) {
		//find closest wall and only cast to closest wall
			castedRay = ray.cast(renderer, wall);

			if ((castedRay.getx() == 0) && (castedRay.gety() == 0) && (castedRay.getz() == 0)) {
				// do nothing
			} else {
				float distance = Vector::dist(pos, castedRay);
				if (distance < shortestDistance) {
					shortestDistance = distance;
					shortestRay = castedRay;
				}
			}
		}

		if (shortestRay.getx() != 0 && shortestRay.gety() != 0) {
			ray.drawRay(renderer, shortestRay.getx(), shortestRay.gety());
		}

		distances.push_back(shortestDistance);
	}

	return distances;
}
