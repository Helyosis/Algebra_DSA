#pragma once

class Transmission {
private:
	int curr_gear;
	char* noises[6] = {
		"* zzz *",
		"R",
		"Rr",
		"Rrr",
		"Brrrm",
		"Brrrrrrrrrrrrrrrrm!"
	};

public:
	Transmission();
	void gear_up();
	void gear_down();
	char* to_string();
};