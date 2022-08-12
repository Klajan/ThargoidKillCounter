#include "Table.h"

using namespace std;

std::wostringstream& Table::makeColumn(const std::wstring& element)
{
	ssC.str(L"");
	ssC << left << setw(width_) << setfill(filler_) << element;
	return ssC;
}

Table::Table(size_t num_columns, size_t column_width, wchar_t fill, wchar_t seperator)
{
	columns_ = num_columns; width_ = column_width; filler_ = fill; seperator_ = seperator;
}

std::wostringstream& Table::makeRow(const std::vector<std::wstring>& elements)
{
	ssR.str(L"");
	ssR << left << seperator_;
	for (size_t i = 0; (i < elements.size()) && i < columns_ ; i++)
	{
		ssR << L" " << makeColumn(elements[i]).str() << seperator_;
		//if ((i + 1 < columns_) || (i == 0)) ssR << seperator_;
	}
	ssR << endl;
	return ssR;
}

std::wostringstream& Table::makeBlankRow(wchar_t fill, wchar_t seperator)
{
	ssR.str(L"");
	static std::wstring empty;
	auto memory = filler_;
	filler_ = fill;
	ssR << left << seperator;
	for (size_t i = 0; i < columns_; i++)
	{
		ssR << fill << makeColumn(empty).str() << seperator;
		//if (((i + 1 < columns_) || (i == 0))) ssR << seperator;
	}
	ssR << endl;
	filler_ = memory;
	return ssR;
}
