#include "Transmission.h"

Transmission::Transmission() {
	curr_gear = 0;
}

void Transmission::gear_down() {
	if (curr_gear > 0)
		curr_gear--;
}

void Transmission::gear_up() {
	if (curr_gear < 5)
		curr_gear++;
}

char* Transmission::to_string() {
	return noises[curr_gear];
}