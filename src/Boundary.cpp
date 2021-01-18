
#include "Boundary.h"
#include "C:\Program Files\SDL2\SDL2-2.0.12\include\SDL.h"

Boundary::Boundary(float x1, float y1, float x2, float y2) {
	a = Vector(x1, x2);
	b = Vector(x2, y2);
}

Boundary::Boundary(int x1, int y1, int x2, int y2) {
	a = Vector(x1, y1);
	b = Vector(x2, y2);
}

Boundary::~Boundary() {
	//delete a;
	//delete b;
}

void Boundary::show(SDL_Renderer* renderer) {
	SDL_RenderDrawLine(renderer, a.getx(), a.gety(), b.getx(), b.gety());
}

float Boundary::getax() {
	return a.getx();
}

float Boundary::getay() {
	return a.gety();
}

float Boundary::getbx() {
	return b.getx();
}

float Boundary::getby() {
	return b.gety();
}