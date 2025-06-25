#include "Time.h"



my_string Time::get_executuon_time()  {
	/*time_t t = time(NULL);
	struct tm date = *localtime(&t);*/

	my_string data_time = "<";
	char buffer[10];

	std::sprintf(buffer, "%d", date->tm_year + 1900);
	data_time += (buffer);
	data_time += ".";
	// Month (tm_mon is 0–11, so add 1)
	std::sprintf(buffer, "%02d", date->tm_mon + 1);
	data_time += (buffer);
	data_time += ".";
	// Day
	std::sprintf(buffer, "%02d", date->tm_mday);
	data_time += (buffer);
	data_time += ">";
	// Hour
	std::sprintf(buffer, "%02d", date->tm_hour);
	data_time += "<";
	data_time += (buffer);
	data_time += ":";
	// Minute
	std::sprintf(buffer, "%02d", date->tm_min);
	data_time += (buffer);
	data_time += ":";
	// Second
	std::sprintf(buffer, "%02d", date->tm_sec);
	data_time += (buffer);
	data_time += ">";

	return data_time;
}