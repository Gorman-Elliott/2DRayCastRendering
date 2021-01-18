
#include "Player.h"

#include <iostream>

Player::Player(Camera camera) {
	cam = camera;
	pos.set(0, 0);
	dir.set(0.6, 0.34641013);
}

Player::Player(Camera camera, int x, int y) {
	camera.updateCameraPos(x, y);
	cam = camera;
	cam = Camera(400, 200);
	pos.set(x, y);
	dir.set(0.6, 0.34641013);
}

void Player::moveDir(SDL_Renderer* renderer, SDL_Texture* texture, std::vector<Boundary> walls, PLAYER_DIR direction, int step) {
	switch (direction) {
		case(PLAYER_DIR::FORWARD):
			pos.set(pos.getx() + (dir.getx()*step), pos.gety() + (dir.gety()*step));
			updateView(renderer, texture, walls, pos);
			break;
		case(PLAYER_DIR::LEFT):
			pos.set(pos.getx() - (dir.getx() * step), pos.gety() + (dir.gety() * step));
			updateView(renderer, texture, walls, pos);
			break;
		case(PLAYER_DIR::BACKWARD):
			pos.set(pos.getx() - (dir.getx() * step), pos.gety() - (dir.gety() * step));
			updateView(renderer, texture, walls, pos);
			break;
		case(PLAYER_DIR::RIGHT):
			pos.set(pos.getx() + (dir.getx() * step), pos.gety() + (dir.gety() * step));
			updateView(renderer, texture, walls, pos);
			break;
	}

	//std::cout << "x: " << pos.getx() << " y: " << pos.gety() << std::endl;

	//Note that LEFT and RIGHT are inversed. This is due to the camera being inverted along the 
	// x-axis because of the raycasting technique
}

void Player::render(SDL_Renderer* renderer) {
	SDL_RenderDrawPoint(renderer, pos.getx(), pos.gety());
}

void Player::update(Vector newPos) {
	pos = newPos;
}

void Player::update(int x, int y) {
	pos.set(x, y);
}

void Player::updateView(SDL_Renderer* renderer, SDL_Texture* texture, std::vector<Boundary> walls, Vector pos) {
	//!!!IMPORTANT clear renderer before updating to create new frame
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_TRANSPARENT);
	SDL_RenderClear(renderer);

	//RESET DRAW COLOR TO WHITE
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_TRANSPARENT);

	render(renderer);
	cam.updateCameraPos(pos);
	cam.updateView(renderer, texture, walls);

}

void Player::panView(SDL_Renderer* renderer, SDL_Texture* texture, std::vector<Boundary> walls, float angle) {
	dir = Vector::fromAngle(angle + dir.getAngle());
	cam.pointCameraAt(angle);
	updateView(renderer, texture, walls, pos);
}


float Player::getx() {
	return pos.getx();
}

float Player::gety() {
	return pos.gety();
}

Vector Player::getPositionVector() {
	return pos;
}