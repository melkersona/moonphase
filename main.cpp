#define PRINT(text) std::cout << text << '\n'
#include <time.h>
#include <math.h>
#include <iostream>
#include <string>

namespace {
	static const double sec_per_day			= 86400.0;
	static const double magic_julian_offset	= 2440587.5;
	static const double known_new_moon		= 2415020.5;
	static const double synodic_month		= 29.53059;
	static const double phase_length		= synodic_month / 8;

	time_t t, bar;
	double julian_date, moon_age, next_phase_age, next_phase_days;
	int normalized_age;
	std::string moon_phase, next_moon_phase, final_output;

	std::string get_formatted_date(time_t date) {
	//	return asctime(localtime(&date));
		struct tm * timeinfo;
		char buffer [80];

		timeinfo = localtime(&date);
		strftime(buffer, 80, "%a %b %d %g", timeinfo);
		return buffer;
	}

	double get_moon_age(double datej) {
		return std::fmod((datej - known_new_moon), synodic_month);
	}

	time_t get_unix_time(double datej) {
		return ((datej + 1 ) - magic_julian_offset) * sec_per_day;
	}

	double get_julian_date(time_t date) {
		return (date / sec_per_day) + magic_julian_offset;
	}

	int normalize_moon_age (double moonage) {
		int normalized_age;
		normalized_age = (moonage / phase_length) + 1;
		return normalized_age;
	}

	double get_moon_age_from_normal(int normal_moonage) {
		return normal_moonage * phase_length;
	}

	std::string get_moon_phase_from_normal(int normal_moonage) {
		switch (normal_moonage) {
			case 1:
				return "New Moon";
			case 2:
				return "Waxing Crescent";
			case 3:
				return "First Quarter";
			case 4:
				return "Waxing Gibbous";
			case 5:
				return "Full Moon";
			case 6:
				return "Waning Gibbous";
			case 7:
				return "Last Quarter";
			case 8:
				return "Waning Crescent";
			default:
				return "New Moon";
		}
	}

	void parseArguments(int argc, char** argv) {
		std::string arg1 	= argv[1];
		julian_date 		= get_julian_date(t);
		bar					= get_unix_time(julian_date);
		moon_age			= get_moon_age(julian_date);
		normalized_age		= normalize_moon_age(moon_age);
		moon_phase			= get_moon_phase_from_normal(normalized_age);
		next_moon_phase		= get_moon_phase_from_normal(normalized_age + 1);
		next_phase_age		= get_moon_age_from_normal(normalized_age);
		next_phase_days		= next_phase_age - moon_age;

		if (arg1.compare("age")						== 0 ) {
			final_output = std::to_string(moon_age);
		} else if (arg1.compare("phase")			== 0 ) {
			final_output = moon_phase;
		} else if (arg1.compare("julian")			== 0 ) {
			final_output = std::to_string(julian_date);
		} else if (arg1.compare("nextphase")		== 0 ) {
			final_output = next_moon_phase + 
				" in " + 
				std::to_string(next_phase_days) + 
				" days";
		} else if (arg1.compare("nextphasedate")	== 0 ) {
			final_output = "Formatted: " + 
				get_formatted_date(t + (next_phase_days * sec_per_day));
		}
		PRINT(final_output);
	}
}

int main(int argc, char** argv) {
	t = time(NULL);

	if (argc == 1) {
		PRINT("Usage:\n"
				<< "moonphase age\t\tPrint the moon's age\n"
				<< "moonphase phase\t\tPrint the moon's phase\n"
				<< "moonphase julian\tPrint the Julian Date\n"
				<< "moonphase nextphase\tPrint the next moon's phase, and how long until it occurs.\n"
				<< "moonphase nextphasedate\tPrint the next moon phase's date.");
	} else if (argc >= 2) {
		parseArguments(argc, argv);
	}

	return 0;
}
