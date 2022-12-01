#pragma once

#include <iostream>
#include "ATarget.hpp"
#include "ASpell.hpp"
#include "SpellBook.hpp"

class Warlock {
	public:
		Warlock(std::string const &name, std::string const &title);
		~Warlock();
		std::string const & getName() const;
		std::string const & getTitle() const;
		void setTitle(std::string const &title);
		void introduce() const;

		void learnSpell(ASpell * spell);
		void forgetSpell(std::string spellName);
		void launchSpell(std::string spellName, ATarget const & target);

	private:
		Warlock();
		Warlock(Warlock const & src);
		Warlock & operator=(Warlock const & src);

		std::string name;
		std::string title;
		SpellBook book;
};
