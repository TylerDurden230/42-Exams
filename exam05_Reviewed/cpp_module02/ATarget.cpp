#include "ATarget.hpp"

ATarget::ATarget() : type("") {}

ATarget::ATarget(std::string const &type) : type(type){}

ATarget::~ATarget(){}

ATarget::ATarget(ATarget const & src){*this = src;}

ATarget & ATarget::operator=(ATarget const & src){this->type = src.type; return *this;}

std::string const & ATarget::getType() const {return type;}

void ATarget::getHitBySpell(ASpell const & spell) const{
	std::cout << type << " has been " << spell.getEffects() << "!" <<std::endl;
}

