
#include "Ray.h"

#include <cmath>
#include <iostream>

Ray::Ray(Vector position, float angle) {
	pos = position;
	//dir = angle;
	dir = Vector::fromAngle(angle);

}

float Ray::getxdir() {
	return dir.getx();
}

float Ray::getydir() {
	return dir.gety();
}

void Ray::drawRay(SDL_Renderer* renderer, float x, float y) {
	SDL_RenderDrawLine(renderer, pos.getx(), pos.gety(), x, y);
}

void Ray::lookAt(int x, int y) {
	dir.set(x - pos.getx(), y - pos.gety());
}

void Ray::pointRayAt(float angle) {
	angle += dir.getAngle();
	dir = Vector::fromAngle(angle);
}


//sets the values in ray::pos
void Ray::set(float x, float y) {
	pos.set(x, y);
}

void Ray::show(SDL_Renderer* renderer) {
	SDL_RenderDrawLine(renderer, pos.getx(), pos.gety(), pos.getx()+(dir.getx()*15), pos.gety()+(dir.gety()*15));
}

Vector Ray::getpos() {
	Vector copy = pos;
	return copy;
}

Vector Ray::cast(SDL_Renderer* renderer, Boundary wall) {
	Vector ray;

	float x1 = wall.getax();
	float y1 = wall.getay();
	float x2 = wall.getbx();
	float y2 = wall.getby();
	float x3 = pos.getx();
	float y3 = pos.gety();
	float x4 = pos.getx() + dir.getx();
	float y4 = pos.gety() + dir.gety();
	
	float denom = ((x1 - x2) * (y3 - y4)) - ((y1 - y2) * (x3 - x4));
	if (denom == 0) {
		ray.set(0, 0, 0);
		return ray;
	}

	float t = ((((x1 - x3) * (y3 - y4)) - ((y1 - y3) * (x3 - x4)))) / (denom);
	float u = -((((x1 - x2) * (y1 - y3)) - ((y1 - y2) * (x1 - x3)))) / (denom);

	if (t > 0 && t < 1 && u > 0) {
		ray.set((x1 + (t * (x2 - x1))), (y1 + (t*(y2 - y1))));
		//drawRay(renderer, ray.getx(), ray.gety());
		return ray;
	}

	else {
		ray.set(0, 0, 0);
		return ray;
	}
	

}

void Ray::setAngle(float degrees) {
	//y is - because Y+ is down and Y- is up on window
	//angle incoming as degrees, convert to radians
	float radians = degrees * (3.14159265358979323846 / 180.0);

	float y = -(Vector::getMagnitude(dir) * sin(radians));
	float x = (Vector::getMagnitude(dir) * cos(radians));


	//std::cout << "dir.x: " << x << " dir.y: " << y << std::endl;
	dir.set(x, y);
	//std::cout << "angle after conversion: " << getAngle() << std::endl;
}