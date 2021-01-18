#pragma once

#include "Vector.h"
#include "C:\Program Files\SDL2\SDL2-2.0.12\include\SDL.h"

class Boundary {
private:
	Vector a;
	Vector b;

public:
	Boundary(float x1, float y1, float x2, float y2);
	Boundary(int x1, int y1, int x2, int y2);
	~Boundary();
	
	float getax();
	float getay();
	float getbx();
	float getby();
	void show(SDL_Renderer *renderer);
};
