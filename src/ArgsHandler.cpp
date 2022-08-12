#include "ArgsHandler.h"

namespace input
{

	//const std::array<const char*, 2> ArgsHandler::argslist {"-path", "-verbose"};

	std::vector<std::pair<Arguments, int>>& ArgsHandler::locateNamedArgs(std::span<const char*> argv)
	{
		std::vector<std::pair<Arguments, int>> out;
		for (int i = 0; i < argv.size(); i++)
		{
			if (argv[i] && argv[i][0] == '-')
			{
				for (int j = 0; j < argslist.size(); j++)
				{
					if (std::strncmp(argv[i], argslist[j], 32) == 0)
					{
						out.push_back(std::pair((Arguments)j, i));
					}
				}
			}
		}
		return out;
	}

	void ArgsHandler::parseArgsList(std::span<const char*> argv)
	{
		if (argv.size() <= 1) return;

		std::vector<std::pair<Arguments, int>> locations = locateNamedArgs(argv);

		for (int i = 0; i < locations.size(); i++)
		{
			switch (locations[i].first)
			{
			case Arguments::path:
				break;
			case Arguments::verbose:
				break;
			default:
				break;
			}
		}
	}
}
