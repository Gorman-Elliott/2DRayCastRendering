#pragma once


#include "Camera.h"
#include "Particle.h"

enum class PLAYER_DIR {
	FORWARD, LEFT, BACKWARD, RIGHT
};

class Player {
private:
	// Note that the player should recieve a camera
	Camera cam;

	Vector pos;
	Vector dir;

public:
	Player(Camera camera);
	Player(Camera camera, int x, int y);

	void render(SDL_Renderer* renderer);
	void update(Vector newPos);
	void update(int x, int y);
	void updateView(SDL_Renderer* renderer, SDL_Texture* texture, std::vector<Boundary> walls, Vector pos);
	void moveDir(SDL_Renderer* renderer, SDL_Texture* texture, std::vector<Boundary> walls, PLAYER_DIR dir, int step);
	void panView(SDL_Renderer* renderer, SDL_Texture* texture, std::vector<Boundary> walls, float angle);

	float getx();
	float gety();
	Vector getPositionVector();

};