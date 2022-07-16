#include "KillCounter.h"

void KillCounter::addKill(Thargoid type)
{
	switch (type)
	{
	case Thargoid::Scout:
		Scout_++;
		break;
	case Thargoid::Cyclops:
		Cyclops_++;
		break;
	case Thargoid::Basilisk:
		Basilisk_++;
		break;
	case Thargoid::Medusa:
		Medusa_++;
		break;
	case Thargoid::Hydra:
		Hydra_++;
		break;
	default:
		Unknown_++;
		break;
	}
}
