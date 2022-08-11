#include "OutputHandler.h"

using namespace std;
namespace Output
{
	void OutputHandler::killsToTable(KillCounter& kills)
	{
		//cout << left << setw(50) << setfill('@') << "@" << endl;
		//cout << "@   "; makeColumn(Thargoid::toString(Thargoid::Scout), nameWidth); makeColumn(kills.Scout(), numWidth); cout << "   @" << endl;
		makeRow("Thargoid Type", "Kill Count");
		makeBlankRow();
		cout << termcolor::bright_grey;
		makeRow(Thargoid::toString(Thargoid::Unknown), std::to_string(kills.Unknown()));
		cout << termcolor::green;
		makeRow(Thargoid::toString(Thargoid::Scout), std::to_string(kills.Scout()));
		cout << termcolor::white;
		makeRow(Thargoid::toString(Thargoid::Cyclops), std::to_string(kills.Cyclops()));
		cout << termcolor::red;
		makeRow(Thargoid::toString(Thargoid::Basilisk), std::to_string(kills.Basilisk()));
		cout << termcolor::magenta;
		makeRow(Thargoid::toString(Thargoid::Medusa), std::to_string(kills.Medusa()));
		cout << termcolor::yellow;
		makeRow(Thargoid::toString(Thargoid::Hydra), std::to_string(kills.Hydra()));
		cout << termcolor::reset;
	}

	template<typename T> void OutputHandler::makeColumn(T t, const int& width)
	{
		OutputHandler::makeColumn(t, width, "");
	}

	template<typename T> void OutputHandler::makeColumn(T t, const int& width, const char* ANSI)
	{
		cout << ANSI;
		cout << left << setw(width) << setfill(separator) << t;
	}

	void OutputHandler::makeRow(std::string a, std::string b)
	{
		OutputHandler::makeRow(a, b, "");
	}

	void OutputHandler::makeRow(std::string a, std::string b, const char* ANSI)
	{
		makeColumn(a, nameWidth, ANSI);
		cout << "| ";
		makeColumn(b, numWidth, ANSI);
		cout << endl;
	}

	void OutputHandler::makeBlankRow()
	{
		cout << termcolor::reset;
		cout << left << setw(nameWidth) << setfill('-') << "-";
		cout << left << setw(numWidth) << setfill('-') << "|" << endl;
	}

	void OutputHandler::setTermColor()
	{
	}

	// begin platform dependent code

#ifdef _WIN32
	OutputHandler::OutputHandler()
	{
		HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		if (hOut != INVALID_HANDLE_VALUE)
		{
			DWORD dwMode = 0;
			if (GetConsoleMode(hOut, &dwMode))
			{
				dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
				SetConsoleMode(hOut, dwMode);
			}
		}
	}
#else
	void OutputHandler::OutputHandler()
	{

	}

	void OutputHandler::setColor(termcolor color)
	{

	}
#endif // _WIN32
}
