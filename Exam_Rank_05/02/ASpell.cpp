
#include "ASpell.hpp"
#include "ATarget.hpp"

ASpell::ASpell() : name(""), effects("") {}

ASpell::ASpell(std::string name, std::string effects) : name(name), effects(effects) {}

ASpell::ASpell(ASpell const & other) { *this = other; } 

ASpell& ASpell::operator=(ASpell const & other) { this->name = other.name; this->effects = other.effects; return (*this); }

ASpell::~ASpell() {} 

std::string ASpell::getName() const { return (name); }

std::string ASpell::getEffects() const { return (effects); }

void ASpell::launch(ATarget const & target) const { target.getHitBySpell(*this); }

