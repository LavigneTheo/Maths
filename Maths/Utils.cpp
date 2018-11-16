#include "Utils.h"


float deg_to_rad(const float& angle) {
	return angle * M_PI / 180;
}
float rad_to_deg(const float& rad) {
	return rad * 180 / M_PI;
}
float round_3dec(const float& value) {
	return round(value * 1000) / 1000.f;
}
