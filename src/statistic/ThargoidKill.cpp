#include "ThargoidKill.h"

ThargoidKill::ThargoidKill()
{
}

ThargoidKill::ThargoidKill(std::shared_ptr<Journal::KillBond> bond)
{
	killBond_ = bond;
}

ThargoidKill::ThargoidKill(std::shared_ptr<Journal::KillBond> bond, std::shared_ptr<Journal::SupercruiseExit> supercruise) : ThargoidKill(bond)
{
	supercruiseExit_ = supercruise;
}

ThargoidKill::ThargoidKill(std::shared_ptr<Journal::KillBond> bond, std::shared_ptr<Journal::SupercruiseExit> supercuise, std::shared_ptr<Journal::USSDrop> drop) : ThargoidKill(bond, supercuise)
{
	ussDrop_ = drop;
}
