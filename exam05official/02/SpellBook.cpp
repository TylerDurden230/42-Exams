
#include "SpellBook.hpp"

SpellBook::SpellBook() { }

SpellBook::~SpellBook()
{
	for (int i = 0; i < spells.size(); i++)
		delete(spells[i]);
	spells.clear();
}

void SpellBook::learnSpell(ASpell *newSpell)
{
	for (int i = 0; i < spells.size(); i++)
	{
		if (newSpell->getName() == spells[i]->getName())
			return ;
	}
	spells.push_back(newSpell->clone());
}

void SpellBook::forgetSpell(std::string const & spellName)
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

ASpell * SpellBook::createSpell(std::string const & spellName)
{
	for (int i = 0; i < spells.size(); i++)
	{
		if (spellName == spells[i]->getName())
			return (spells[i]);
	}
}
