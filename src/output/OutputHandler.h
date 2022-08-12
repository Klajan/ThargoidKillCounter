#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <locale>
#include <termcolor/termcolor.hpp>

#include "../statistic/KillCounter.h"
#include "../Thargoid.hpp"
#include "Table.h"
#include "../string_helpers.h"

#ifdef _WIN32
#include <io.h>
#include <fcntl.h>
#endif

namespace Output
{
	class OutputHandler
	{
	private:
		const char separator = ' ';
		const int nameWidth = 14;
		const int numWidth = 13;

		template<typename T> void makeColumn_deprecated(T t, const int& width);
		template<typename T> void makeColumn_deprecated(T t, const int& width, const char*);
		void makeRow_deprecated(std::string, std::string);
		void makeRow_deprecated(std::string, std::string, const char*);
		void makeBlankRow_deprecated();

	public:
		OutputHandler();
		void killsToTable(KillCounter&);
	};
}
