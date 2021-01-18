#pragma once

#include "Particle.h" //includes "Vector", "Boundary", "Ray"

class Camera {
private:
	Vector origin; //Set origin of camera pos for drawing scene, typically top left of window (0, 0)
	Vector pos;

	//Direction of camera, representing the middle of the field of view
	Vector dir;
	Particle particle;
	std::vector<float> scene;
	void drawView(SDL_Renderer* renderer, SDL_Texture* texture, std::vector<Boundary> walls);
	float map(float value, float istart, float istop, float ostart, float ostop);

public:
	Camera();
	Camera(int fov);
	Camera(int x, int y);
	Camera(int x, int y, int fov);
	void updateView(SDL_Renderer* renderer, SDL_Texture* texture, std::vector<Boundary> walls); // in update, camera cast rays using particle, draws the view, and takes input to change view
	void updateCameraPos(int x, int y);
	void updateCameraPos(Vector newPos);

	//updates the camera angle in steps
	void pointCameraAt(float angle);

	//changes the camera angle completely, not just in steps
	void updateCameraAngle(Vector angle);
};