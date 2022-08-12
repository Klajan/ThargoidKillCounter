#include "OutputHandler.h"

using namespace std;
namespace Output
{
	void OutputHandler::killsToTable(KillCounter& kills)
	{
		//L'\u2502'
		Table table(3, 15, L' ', L'\u2503');
		//cout << left << setw(50) << setfill('@') << "@" << endl;
		//cout << "@   "; makeColumn(Thargoid::toString(Thargoid::Scout), nameWidth); makeColumn(kills.Scout(), numWidth); cout << "   @" << endl;
		/*makeRow_deprecated("Thargoid Type", "Kill Count");
		makeBlankRow();
		cout << termcolor::bright_grey;
		makeRow_deprecated(Thargoid::toString(Thargoid::Unknown), std::to_string(kills.Unknown()));
		cout << termcolor::green;
		makeRow_deprecated(Thargoid::toString(Thargoid::Scout), std::to_string(kills.Scout()));
		cout << termcolor::white;
		makeRow_deprecated(Thargoid::toString(Thargoid::Cyclops), std::to_string(kills.Cyclops()));
		cout << termcolor::red;
		makeRow_deprecated(Thargoid::toString(Thargoid::Basilisk), std::to_string(kills.Basilisk()));
		cout << termcolor::magenta;
		makeRow_deprecated(Thargoid::toString(Thargoid::Medusa), std::to_string(kills.Medusa()));
		cout << termcolor::yellow;
		makeRow_deprecated(Thargoid::toString(Thargoid::Hydra), std::to_string(kills.Hydra()));
		cout << termcolor::reset;
		*/
		vector<wstring> header{ L"Thargoid Type", L"Kill Count", L"Total Reward"};
		wcout << table.makeRow(header).str();
		wcout << table.makeBlankRow(L'\u2501', L'\u254B').str();
		wcout << termcolor::bright_grey;
		wcout << table.makeRow(vector<wstring> {Thargoid::to_wstring(Thargoid::Unknown), std::to_wstring(kills.Unknown()), humanize::whumanize_metric(kills.RewardUnknownd(), 1)}).str();
		wcout << termcolor::green;
		wcout << table.makeRow(vector<wstring> {Thargoid::to_wstring(Thargoid::Scout), std::to_wstring(kills.Scout()), humanize::whumanize_metric(kills.RewardScout(), 1)}).str();
		wcout << termcolor::white;
		wcout << table.makeRow(vector<wstring> {Thargoid::to_wstring(Thargoid::Cyclops), std::to_wstring(kills.Cyclops()), humanize::whumanize_metric(kills.RewardCyclops(), 1)}).str();
		wcout << termcolor::red;
		wcout << table.makeRow(vector<wstring> {Thargoid::to_wstring(Thargoid::Basilisk), std::to_wstring(kills.Basilisk()), humanize::whumanize_metric(kills.RewardBasilisk(), 1)}).str();
		wcout << termcolor::magenta;
		wcout << table.makeRow(vector<wstring> {Thargoid::to_wstring(Thargoid::Medusa), std::to_wstring(kills.Medusa()), humanize::whumanize_metric(kills.RewardMedusa(), 1)}).str();
		wcout << termcolor::yellow;
		wcout << table.makeRow(vector<wstring> {Thargoid::to_wstring(Thargoid::Hydra), std::to_wstring(kills.Hydra()), humanize::whumanize_metric(kills.RewardHydra(), 1)}).str();
		wcout << termcolor::reset << flush;
		wcout << table.makeBlankRow(L'\u2501', L'\u254B').str();
	}

	template<typename T> void OutputHandler::makeColumn_deprecated(T t, const int& width)
	{
		OutputHandler::makeColumn_deprecated(t, width, "");
	}

	template<typename T> void OutputHandler::makeColumn_deprecated(T t, const int& width, const char* ANSI)
	{
		cout << ANSI;
		cout << left << setw(width) << setfill(separator) << t;
	}

	void OutputHandler::makeRow_deprecated(std::string a, std::string b)
	{
		OutputHandler::makeRow_deprecated(a, b, "");
	}

	void OutputHandler::makeRow_deprecated(std::string a, std::string b, const char* ANSI)
	{
		makeColumn_deprecated(a, nameWidth, ANSI);
		cout << "| ";
		makeColumn_deprecated(b, numWidth, ANSI);
		cout << endl;
	}

	void OutputHandler::makeBlankRow_deprecated()
	{
		cout << termcolor::reset;
		cout << left << setw(nameWidth) << setfill('-') << "-";
		cout << left << setw(numWidth) << setfill('-') << "|" << endl;
	}

	OutputHandler::OutputHandler()
	{

	}
}
