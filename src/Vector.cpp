
#include "Vector.h"
#include <cmath>
#include <iostream>

Vector::Vector() {
	vx = 0;
	vy = 0;
	vz = 0;
}


Vector::Vector(int x, int y) {
	vx = x;
	vy = y;
	vz = 0;
}

Vector::Vector(float x, float y) {
	vx = x;
	vy = y;
	vz = 0;
}

Vector::Vector(int x, int y, int z) {
	vx = x;
	vy = y;
	vz = z;
}

Vector::Vector(float x, float y, float z) {
	vx = x;
	vy = y;
	vz = z;
}

void Vector::set(float x, float y)
{
	vx = x;
	vy = y;
}

void Vector::set(float x, float y, float z) {
	vx = x;
	vy = y;
	vz = z;
}

float Vector::getx() {
	return vx;
}

float Vector::gety() {
	return vy;
}

float Vector::getz() {
	return vz;
}

float Vector::dist(Vector one, Vector two) {
	float distance = sqrt(pow(two.vx - one.vx , 2) + pow(two.vy - one.vy, 2));
	return distance;
}

Vector Vector::fromAngle(float angle)
{
	
	float a = Vector::radians(angle);
	if (angle > 360) angle = 0;

	//std::cout << "a: " << a << std::endl;
	Vector v;
	if (angle >= 0 && angle <= 90) {
		v = Vector(cos(a), sin(a));
	}
	else if (angle > 90 && angle <= 180) {
		v = Vector(cos(-a), sin(a));
	}
	else if (angle > 180 && angle <= 270) {
		v = Vector(cos(-a), -sin(-a));
	}
	else if (angle > 270 && angle <= 360 || angle < 0 && angle > -90) {
		v = Vector(cos(a), -sin(-a));
	}

	return v;
}


float Vector::getAngle() {
	// If the angle is in a quadrant other than the first, we need to add 90, 180, 270 to the angle
	// based on +/- values of x, y as per the unit circle

	if (getx() == 0 && gety() == 0) return 0;

	if (getx() < 0 && gety() > 0) {
		float tq = abs(((180 / 3.14159265358979323846) * atan(gety() / getx())));
		return 180 - tq;
	}
	else if (getx() < 0 && gety() < 0) {
		float tq = abs(((180 / 3.14159265358979323846) * atan(gety() / getx())));
		return 180 + tq;
	}
	else if (getx() > 0 && gety() < 0) {
		float tq = abs(((180 / 3.14159265358979323846) * atan(gety() / getx())));
		return 360 - tq;
	}
	else {
		return abs(((180 / 3.14159265358979323846) * atan(gety() / getx())));
	}


}


float Vector::radians(float degrees) {
	float angle = (degrees * (3.14159265358979323846 / 180));
	return angle;
}

float Vector::getMagnitude(Vector v) {
	return sqrt(pow(v.getx(), 2) + pow(v.gety(), 2));
}


