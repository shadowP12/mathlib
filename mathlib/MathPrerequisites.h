#pragma once
#include <cmath>
#define PI 3.1415926

float Radians(float degrees) {
	return (PI / 180.0f) * degrees;
}

float Degrees(float radians) {
	return (radians * 180.0) / PI;
}

void Swap(float& a, float& b) {
	float t = a;
	a = b;
	b = t;
}
