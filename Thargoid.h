#pragma once
#include <string>

class Thargoid
{
public:
	enum Value : int
	{
		Unknown		= 0,
		Scout		= 80000,
		Cyclops		= 8000000,
		Basilisk	= 24000000,
		Medusa		= 40000000,
		Hydra		= 60000000
	};

	Thargoid() = default;
	constexpr Thargoid(Value aThargoid) : value(aThargoid) { }
	constexpr operator Value() const { return value; }
	explicit operator bool() const = delete;
	constexpr bool operator==(Thargoid a) const { return value == a.value; }
	constexpr bool operator!=(Thargoid a) const { return value != a.value; }

	constexpr Thargoid(int val)
	{
		switch (val)
		{
		case Thargoid::Scout:
			value = Thargoid::Scout;
			break;
		case Thargoid::Cyclops:
			value = Thargoid::Cyclops;
			break;
		case Thargoid::Basilisk:
			value = Thargoid::Basilisk;
			break;
		case Thargoid::Medusa:
			value = Thargoid::Medusa;
			break;
		case Thargoid::Hydra:
			value = Thargoid::Hydra;
			break;
		default:
			value = Thargoid::Unknown;
			break;
		}
	}

	constexpr Thargoid& operator= (const int val)
	{
		switch (val)
		{
		case Thargoid::Scout:
			value = Thargoid::Scout;
			break;
		case Thargoid::Cyclops:
			value = Thargoid::Cyclops;
			break;
		case Thargoid::Basilisk:
			value = Thargoid::Basilisk;
			break;
		case Thargoid::Medusa:
			value = Thargoid::Medusa;
			break;
		case Thargoid::Hydra:
			value = Thargoid::Hydra;
			break;
		default:
			value = Thargoid::Unknown;
			break;
		}
		return *this;
	}

	constexpr operator std::string()
	{
		switch (value)
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

	static std::string toString(Value val)
	{
		return (std::string)Thargoid(val);
	}

private:
	Value value;
};