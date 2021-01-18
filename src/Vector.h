#pragma once

class Vector {

private:
	float vx, vy, vz;

public:
	Vector();
	Vector(float x, float y);
	Vector(int x, int y);
	Vector(int x, int y, int z);
	Vector(float x, float y, float z);
	void set(float x, float y);
	void set(float x, float y, float z);
	float getx();
	float gety();
	float getz();
	static float radians(float degrees);
	static float dist(Vector one, Vector two);
	static Vector fromAngle(float angle);
	static float getMagnitude(Vector v);

	//returns current angle of dir vector in degrees
	float getAngle();

};