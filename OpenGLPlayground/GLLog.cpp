#include "GLLog.h"
#include <fstream>
#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

bool restartGlLog()
{
	fstream file(GL_LOG_FILE, ofstream::out | ofstream::trunc);

	if (!file.good())
	{
		cerr << "ERROR: could not open gl log file for writing!" << endl;
		return false;
	}

	struct tm timeinfo;
	auto now = time(nullptr);
	localtime_s(&timeinfo, &now);

	file << "local time " << put_time(&timeinfo, "%d-%m-%Y %H-%M-%S") << endl;
	file.close();

	return true;
}


