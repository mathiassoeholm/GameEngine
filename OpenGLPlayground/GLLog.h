#pragma once

#define GL_LOG_FILE "gl.log"
#include <fstream>
#include <iostream>

bool restartGlLog();

template <typename T>
void glLog(T m)
{
	std::ofstream file(GL_LOG_FILE, std::fstream::app);

	if (!file.is_open())
	{
		std::cerr << "ERROR: could not open gl log file for writing!" << std::endl;
	}

	file << m << std::endl;

	file.close();
}

template<typename T, typename... Args>
void glLog(T m, Args... args) 
{
	// Recursive variadic function
	glLog(m);
	glLog(args...);
}

template <typename T>
void glLogErr(T m)
{
	std::ofstream file(GL_LOG_FILE, std::fstream::app);

	if (!file.is_open())
	{
		std::cerr << "ERROR: could not open gl log file for writing!" << std::endl;
	}

	std::cerr << m << std::endl;
	file << m << std::endl;

	file.close();
}

template<typename T, typename... Args>
void glLogErr(T m, Args... args)
{
	// Recursive variadic function
	glLogErr(m);
	glLogErr(args...);
}