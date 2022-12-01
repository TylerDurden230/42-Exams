#pragma once

#include <iostream>

class ATarget;


class ASpell {
	public:
		ASpell();
		ASpell(std::string const &name, std::string const &effects);
		virtual ~ASpell();
		ASpell(ASpell const & src);
		ASpell & operator=(ASpell const & src);
		std::string const & getName() const;
		std::string const & getEffects() const;
		virtual ASpell * clone() const = 0;
		void launch(ATarget const & target) const;

	protected:
		std::string name;
		std::string effects;
};
