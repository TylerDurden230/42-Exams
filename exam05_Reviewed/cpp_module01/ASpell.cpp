#include "ASpell.hpp"
#include "ATarget.hpp"

ASpell::ASpell() : name(""), effects("") {}

ASpell::ASpell(std::string const &name, std::string const &effects) : name(name), effects(effects){}

ASpell::~ASpell(){}

ASpell::ASpell(ASpell const & src){*this = src;}

ASpell & ASpell::operator=(ASpell const & src){this->name = src.name; this->effects = src.effects; return *this;}

std::string const & ASpell::getName() const {return name;}

std::string const & ASpell::getEffects() const {return effects;}

void ASpell::launch(ATarget const & target) const {
	target.getHitBySpell(*this);
}

