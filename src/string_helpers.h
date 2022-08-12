#pragma once
#include <string>

namespace convert
{
	std::wstring string_to_wstring_utf(const std::string& str);
	std::string wstring_to_string_utf(const std::wstring& wstr);
}
namespace humanize
{
	namespace helpers
	{
		static enum metric_powers : uint64_t
		{
			kilo = 1000,
			mega = 1000000,
			giga = 1000000000,
			tera = 1000000000000,
			peta = 1000000000000000,
			exa = 1000000000000000000
		};
		static enum class metric_prefix : char
		{
			none = NULL,
			kilo = 'k',
			mega = 'M',
			giga = 'G',
			tera = 'T',
			peta = 'P',
			exa = 'E'
		};
		static constexpr char decimal_seperator = '.';
		static inline std::tuple<uint64_t, uint64_t, metric_prefix> calc_humanize_metric(uint64_t);
	}
	std::string humanize_metric(int64_t number, uint32_t precission = 2);
	std::string humanize_metric(uint64_t number, uint32_t precission = 2);
	std::wstring whumanize_metric(int64_t number, uint32_t precission = 2);
	std::wstring whumanize_metric(uint64_t number, uint32_t precission = 2);
}
