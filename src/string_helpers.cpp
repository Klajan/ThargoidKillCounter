#include "string_helpers.h"
#include <iomanip>
#include <string>
#include <locale>
#include <sstream>
#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>
#endif // _WIN32

#ifdef _WIN32
	std::wstring convert::string_to_wstring_utf(const std::string& str)
	{
		int size = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, NULL, 0);
		if (size <= 0) return std::wstring();
		wchar_t* wbuf = new wchar_t[size];
		MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, &wbuf[0], size);
		std::wstring out(wbuf);
		delete[] wbuf;
		return out;
	}
	std::string convert::wstring_to_string_utf(const std::wstring& wstr)
	{
		int size = WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(), -1, NULL, 0, NULL, NULL);
		if (size <= 0) return std::string();
		char* buf = new char[size];
		WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(), -1, &buf[0], size, NULL, NULL);
		std::string out(buf);
		delete[] buf;
		return out;
	}
#endif // _WIN32

	namespace humanize
	{
		std::string humanize::humanize_metric(int64_t number, uint32_t precission )
		{
			auto str = humanize_metric(static_cast<uint64_t>(std::abs(number)), precission);
			if (number < 0) str.insert(0, "-");
			return str;
		}

		std::string humanize::humanize_metric(uint64_t number, uint32_t precission)
		{
			auto result = helpers::calc_humanize_metric(number);

			uint64_t full = std::get<0>(result);
			uint64_t remain = std::get<1>(result);
			helpers::metric_prefix power = std::get<2>(result);

			std::stringstream str;
			str << full;
			if (precission != 0 && remain != 0)
			{
				str << helpers::decimal_seperator << std::setfill('0') << std::setw(precission) << std::to_string(remain).substr(0, precission);
			}
			if (power != helpers::metric_prefix::none)
			{
				str << static_cast<char>(power);
			}

			return str.str();
		}

		std::wstring humanize::whumanize_metric(int64_t number, uint32_t precission)
		{
			auto str = whumanize_metric(static_cast<uint64_t>(std::abs(number)), precission);
			if (number < 0) str.insert(0, L"-");
			return str;
		}

		std::wstring humanize::whumanize_metric(uint64_t number, uint32_t precission)
		{
			auto result = helpers::calc_humanize_metric(number);

			uint64_t full = std::get<0>(result);
			uint64_t remain = std::get<1>(result);
			helpers::metric_prefix power = std::get<2>(result);

			std::wstringstream str;
			str << full;
			if (precission != 0 && remain != 0)
			{
				str << helpers::decimal_seperator << std::setfill(L'0') << std::setw(precission) << std::to_wstring(remain).substr(0, precission);
			}
			if (power != helpers::metric_prefix::none)
			{
				str << static_cast<char>(power);
			}

			return str.str();
		}

		std::tuple<uint64_t, uint64_t, helpers::metric_prefix> helpers::calc_humanize_metric(uint64_t number)
		{
			uint64_t full = 0;
			uint64_t remain = 0;
			helpers::metric_prefix power = helpers::metric_prefix::none;

			if (number >= helpers::metric_powers::exa)
			{
				full = number / helpers::metric_powers::exa;
				remain = number % helpers::metric_powers::exa;
				power = helpers::metric_prefix::exa;
			}
			else if (number >= helpers::metric_powers::peta)
			{
				full = number / helpers::metric_powers::peta;
				remain = number % helpers::metric_powers::peta;
				power = helpers::metric_prefix::peta;
			}
			else if (number >= helpers::metric_powers::tera)
			{
				full = number / helpers::metric_powers::tera;
				remain = number % helpers::metric_powers::tera;
				power = helpers::metric_prefix::tera;
			}
			else if (number >= helpers::metric_powers::giga)
			{
				full = number / helpers::metric_powers::giga;
				remain = number % helpers::metric_powers::giga;
				power = helpers::metric_prefix::giga;
			}
			else if (number >= helpers::metric_powers::mega)
			{
				full = number / helpers::metric_powers::mega;
				remain = number % helpers::metric_powers::mega;
				power = helpers::metric_prefix::mega;
			}
			else if (number >= helpers::metric_powers::kilo)
			{
				full = number / helpers::metric_powers::kilo;
				remain = number % helpers::metric_powers::kilo;
				power = helpers::metric_prefix::kilo;
			}
			else
			{
				full = number;
				remain = 0;
				power = helpers::metric_prefix::none;
			}

			return std::make_tuple(full, remain, power);
		}
	}
