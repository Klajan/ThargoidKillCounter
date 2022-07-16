#include "OutputHandler.h"

using namespace std;

void OutputHandler::killsToTable(KillCounter& kills)
{
	//cout << left << setw(50) << setfill('@') << "@" << endl;
	//cout << "@   "; makeColumn(Thargoid::toString(Thargoid::Scout), nameWidth); makeColumn(kills.Scout(), numWidth); cout << "   @" << endl;
	makeRow("Thargoid Type", "Kill Count", ANSIRESET);
	makeBlankRow();
	makeRow(Thargoid::toString(Thargoid::Unknown), std::to_string(kills.Unknown()), ANSIRESET);
	makeRow(Thargoid::toString(Thargoid::Scout), std::to_string(kills.Scout()), ANSICYAN);
	makeRow(Thargoid::toString(Thargoid::Cyclops), std::to_string(kills.Cyclops()), ANSIWHITE);
	makeRow(Thargoid::toString(Thargoid::Basilisk), std::to_string(kills.Basilisk()), ANSIRED);
	makeRow(Thargoid::toString(Thargoid::Medusa), std::to_string(kills.Medusa()), ANSIMAGENTA);
	makeRow(Thargoid::toString(Thargoid::Hydra), std::to_string(kills.Hydra()), ANSIYELLOW);
	cout << ANSIRESET;
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
	cout << ANSIWHITE;
	cout << left << setw(nameWidth) << setfill('-') << "-";
	cout << left << setw(numWidth) << setfill('-') << "|" << endl;
}