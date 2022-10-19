
#include "Warlock.hpp"

Warlock::Warlock(std::string name, std::string title) : name(name), title(title)
{
	std::cout<<name<<": This looks like another boring day."<<std::endl;
}

Warlock::~Warlock()
{
	std::cout<<name<<": My job here is done!"<<std::endl;
}

std::string const & Warlock::getName() const { return (name); }

std::string const & Warlock::getTitle() const { return (title); }

void    Warlock::setTitle(std::string const & title) { this->title = title; }

void Warlock::introduce() const { std::cout<<name<<": I am "<<name<<", "<<title<<"!"<<std::endl; }

void Warlock::learnSpell(ASpell *newSpell)
{
	book.learnSpell(newSpell);	
}

void Warlock::forgetSpell(std::string const & spellName)
{
	book.forgetSpell(spellName);	
}

void Warlock::launchSpell(std::string const & spellName, ATarget const & target)
{
	ASpell *tmp = book.createSpell(spellName);
	if (tmp)
		tmp->launch(target);	
}


