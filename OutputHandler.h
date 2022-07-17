#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include "include/termcolor/termcolor.hpp"

#include "KillCounter.h"
#include "Thargoid.h"

class OutputHandler
{
private:
	const char separator = ' ';
	const int nameWidth = 14;
	const int numWidth = 13;

	template<typename T> void makeColumn(T t, const int& width);
	template<typename T> void makeColumn(T t, const int& width, const char*);
	void makeRow(std::string, std::string);
	void makeRow(std::string, std::string, const char*);
	void makeBlankRow();

public:
	OutputHandler();
	void killsToTable(KillCounter&);
	void setTermColor();
};
