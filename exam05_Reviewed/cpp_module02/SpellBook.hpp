#pragma once

#include <iostream>
#include "ATarget.hpp"
#include "ASpell.hpp"
#include <vector>

class SpellBook {
	public:
		SpellBook();
		~SpellBook();

		void learnSpell(ASpell * spell);
		void forgetSpell(std::string const & spellName);
		ASpell * createSpell(std::string const & spellName);

	private:
		SpellBook(SpellBook const & src);
		SpellBook & operator=(SpellBook const & src);
		std::vector<ASpell *> spells;
};
