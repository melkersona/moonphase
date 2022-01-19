#define PRINT(text) std::cout << text
#include <time.h>
#include <math.h>
#include <iostream>
#include <algorithm>
static const int sec_per_day = 86400;
static const double magic_julian_offset = 2440587.5;
static const double known_new_moon = 2415020.5;
static const double synodic_month = 29.53059;
static const double phase_length = synodic_month / 8;

int main(int argc, char** argv) {
	time_t t;
	if (argc == 1) {
		t = time(NULL);
		t = (t / sec_per_day) + magic_julian_offset;
		double moon_age = std::fmod((t - known_new_moon), synodic_month);
		if ( moon_age <= phase_length * 1 ) {
			PRINT("New Moon");
		} else if (moon_age <= phase_length * 2) {
			PRINT("Waxing Crescent");
		} else if (moon_age <= phase_length * 3 ) {
			PRINT("First Quarter");
		} else if (moon_age <= phase_length * 4) {
			PRINT("Waxing Gibbous");
		} else if (moon_age <= phase_length * 5) {
			PRINT("Full Moon");
		} else if (moon_age <= phase_length * 6) {
			PRINT("Waning Gibbous");
		} else if (moon_age <= phase_length * 7) {
			PRINT("Last Quarter");
		} else if (moon_age <= phase_length * 8) {
			PRINT("Waning Crescent");
		} else {
			PRINT("New Moon");
		}
	} else if (argc >= 2) {
		for (int i = 1; i < argc; ++i) {
			PRINT(argv[i]<< '\n');
		}
	//	t = time(argv[0])
	}

	return 0;
}
