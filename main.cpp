#define PRINT(text) std::cout << text << '\n'
#include <time.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <string>
static const int sec_per_day = 86400;
static const double magic_julian_offset = 2440587.5;
static const double known_new_moon = 2415020.5;
static const double synodic_month = 29.53059;
static const double phase_length = synodic_month / 8;
time_t t;
double julian_date;
double moon_age;
std::string moon_phase;

double get_moon_age(double datej) {
	return std::fmod((datej - known_new_moon), synodic_month);
}

double get_julian_date(time_t date) {
	return (date / sec_per_day) + magic_julian_offset;
}

std::string get_moon_phase(double moonage) {
	if ( moonage <= phase_length * 1 ) {
		return "New Moon";
	} else if (moonage <= phase_length * 2) {
		return "Waxing Crescent";
	} else if (moonage <= phase_length * 3 ) {
		return "First Quarter";
	} else if (moonage <= phase_length * 4) {
		return "Waxing Gibbous";
	} else if (moonage <= phase_length * 5) {
		return "Full Moon";
	} else if (moonage <= phase_length * 6) {
		return "Waning Gibbous";
	} else if (moonage <= phase_length * 7) {
		return "Last Quarter";
	} else if (moonage <= phase_length * 8) {
		return "Waning Crescent";
	} else {
		return "New Moon";
	}
}

void parseArguments(int argc, char** argv) {
	std::string arg1 = argv[1];
	if (arg1.compare("age")== 0) {
		moon_age = get_moon_age(get_julian_date(t));
		PRINT(moon_age);
	} else if (arg1.compare("phase")==0) {
		julian_date = get_julian_date(t);
		moon_age = get_moon_age(julian_date);
		moon_phase = get_moon_phase(moon_age);
		PRINT(moon_phase);
	} else if (arg1.compare("julian")==0) {
		julian_date = get_julian_date(t);
		PRINT(julian_date);
	}
}

int main(int argc, char** argv) {
	t = time(NULL);
	if (argc == 1) {
		PRINT("Usage:\n"
				<< "moonphase age\t\tPrint the moon's age\n"
				<< "moonphase phase\t\tPrint the moon's phase\n"
				<< "moonphase julian\tPrint the Julian Date");
	} else if (argc >= 2) {
		parseArguments(argc, argv);
	}
	return 0;
}
