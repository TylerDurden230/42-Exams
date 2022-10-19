
#include "Warlock.hpp"

Warlock::Warlock(std::string name, std::string title) : name(name), title(title)
{
	std::cout<<name<<": This looks like another boring day."<<std::endl;
}

Warlock::~Warlock()
{
	std::cout<<name<<": My job here is done!"<<std::endl;
	for (int i = 0; i < spells.size(); i++)
		delete(spells[i]);
	spells.clear();
}

std::string const & Warlock::getName() const { return (name); }

std::string const & Warlock::getTitle() const { return (title); }

void    Warlock::setTitle(std::string const & title) { this->title = title; }

void Warlock::introduce() const { std::cout<<name<<": I am "<<name<<", "<<title<<"!"<<std::endl; }

void Warlock::learnSpell(ASpell *newSpell)
{
	for (int i = 0; i < spells.size(); i++)
	{
		if (newSpell->getName() == spells[i]->getName())
			return ;
	}
	spells.push_back(newSpell->clone());
}

void Warlock::forgetSpell(std::string spellName)
{
	for (int i = 0; i < spells.size(); i++)
	{
		if (spellName == spells[i]->getName())
		{
			delete(spells[i]);
			spells.erase(spells.begin() + i);
			return ;
		}
	}
}

void Warlock::launchSpell(std::string spellName, ATarget& target)
{
	for (int i = 0; i < spells.size(); i++)
	{
		if (spellName == spells[i]->getName())
			return (spells[i]->launch(target));
	}
}


