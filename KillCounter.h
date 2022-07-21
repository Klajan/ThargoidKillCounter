#pragma once
#include "Thargoid.hpp"

class KillCounter
{
	int Scout_ = 0;
	int Cyclops_ = 0;
	int Basilisk_ = 0;
	int Medusa_ = 0;
	int Hydra_ = 0;
	int Unknown_ = 0;

public: 
	int Scout() const { return Scout_; }
	int Cyclops() const { return Cyclops_; }
	int Basilisk() const { return Basilisk_; }
	int Medusa() const { return Medusa_; }
	int Hydra() const { return Hydra_; }
	int Unknown() const { return Unknown_; }

	void addKill(Thargoid type);
};

