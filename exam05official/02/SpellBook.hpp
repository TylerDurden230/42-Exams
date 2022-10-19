
#include <string>
#include <iostream>

#include "ASpell.hpp"
#include <vector>

class SpellBook
{
	public:
		SpellBook();
		~SpellBook();
	
		void learnSpell(ASpell *newSpell);
		void forgetSpell(std::string const & spellName);
		ASpell * createSpell(std::string const & spellName);
	private:
		SpellBook(SpellBook const & other);
		SpellBook& operator=(SpellBook const & other);
	
		std::vector<ASpell *> spells;
};

