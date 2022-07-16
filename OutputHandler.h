#pragma once
#include <iostream>
#include <iomanip>
#include <string>

#include "KillCounter.h"
#include "Thargoid.h"
#include "ANSICodes.h"

static class OutputHandler
{
private:
	static const char separator = ' ';
	static const int nameWidth = 14;
	static const int numWidth = 13;

	template<typename T> static void makeColumn(T t, const int& width);
	template<typename T> static void makeColumn(T t, const int& width, const char*);
	static void makeRow(std::string, std::string);
	static void makeRow(std::string, std::string, const char*);
	static void makeBlankRow();

public:
	static void killsToTable(KillCounter&);
};
