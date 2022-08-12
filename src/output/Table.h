#pragma once
#include <iostream>
#include <sstream>
#include <vector>
#include <iomanip>

class Table
{
private:
	size_t columns_ = 1;
	size_t width_ = 10;
	wchar_t filler_ = L' ';
	wchar_t seperator_ = NULL;

	std::wostringstream ssC;
	std::wostringstream ssR;

	std::wostringstream& makeColumn(const std::wstring& element);
public:
	Table(size_t num_columns, size_t column_width, wchar_t fill, wchar_t seperator);
	std::wostringstream& makeRow(const std::vector<std::wstring>& elements);
	std::wostringstream& makeBlankRow(wchar_t fill, wchar_t seperator);
};

