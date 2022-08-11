#pragma once
#include <string>

class Thargoid
{
private:
	enum Value_Horizon : int
	{
		Scout_old = 20000,
		Cyclops_old = 2000000,
		Basilisk_old = 6000000,
		Medusa_old = 10000000,
		Hydra_old = 15000000
	};
public:
	enum Class : int
	{
		Unknown			= 0,
		Scout			= 80000,
		Cyclops			= 8000000,
		Basilisk		= 24000000,
		Medusa			= 40000000,
		Hydra			= 60000000
	};

	Thargoid() = default;
	constexpr Thargoid(Class aThargoid) : value(aThargoid) { }
	constexpr operator Class() const { return value; }
	explicit operator bool() const = delete;
	constexpr bool operator==(Thargoid a) const { return value == a.value; }
	constexpr bool operator!=(Thargoid a) const { return value != a.value; }

	Thargoid(int val)
	{
		value = fromInt(val);
	}

	Thargoid& operator= (const int val)
	{
		value = fromInt(val);
		return *this;
	}

	operator std::string()
	{
		return Thargoid::to_string(value);
	}

	operator std::wstring()
	{
		return Thargoid::to_wstring(value);
	}

	std::string to_string() const
	{
		return Thargoid::to_string(value);
	}

	std::wstring to_wstring() const
	{
		return Thargoid::to_wstring(value);
	}

	static std::string to_string(Class val)
	{
		switch (val)
		{
		case Thargoid::Scout:
			return "Scout";
		case Thargoid::Cyclops:
			return "Cyclops";
		case Thargoid::Basilisk:
			return "Basilisk";
		case Thargoid::Medusa:
			return "Medusa";
		case Thargoid::Hydra:
			return "Hydra";
		default:
			return "Unknown";
		}
	}
	static std::wstring to_wstring(Class val)
	{
		switch (val)
		{
		case Thargoid::Scout:
			return L"Scout";
		case Thargoid::Cyclops:
			return L"Cyclops";
		case Thargoid::Basilisk:
			return L"Basilisk";
		case Thargoid::Medusa:
			return L"Medusa";
		case Thargoid::Hydra:
			return L"Hydra";
		default:
			return L"Unknown";
		}
	}

private:
	Class value;

	static Thargoid fromInt(int val)
	{
		switch (val)
		{
		case Thargoid::Scout_old:
		case Thargoid::Scout:
			return Thargoid::Scout;
		case Thargoid::Cyclops_old:
		case Thargoid::Cyclops:
			return Thargoid::Cyclops;
		case Thargoid::Basilisk_old:
		case Thargoid::Basilisk:
			return Thargoid::Basilisk;
		case Thargoid::Medusa_old:
		case Thargoid::Medusa:
			return Thargoid::Medusa;
		case Thargoid::Hydra_old:
		case Thargoid::Hydra:
			return Thargoid::Hydra;
		default:
			return Thargoid::Unknown;
		}
	}
};