#pragma once
#include <string>
#include <vector>
#include <span>
#include <tuple>
#include <array>
#include <termcolor/termcolor.hpp>

namespace input
{
	const enum Arguments
	{
		path, verbose
	};

	class ArgsHandler
	{
	private:
		static constexpr std::array argslist { "-path", "-verbose" };
		static std::vector<std::pair<Arguments, int>>& locateNamedArgs(std::span<const char*>);

	public:
		void parseArgsList(std::span<const char*>);
	};
}
