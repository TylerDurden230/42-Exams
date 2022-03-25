
#ifndef ASPELL_HPP
# define ASPELL_HPP

#include <string>

class ATarget;

class ASpell
{
	public:
		ASpell();
		ASpell(std::string name, std::string effects);
		ASpell(ASpell const & other);
		ASpell& operator=(ASpell const & other);
		virtual ~ASpell();

		std::string getName() const;
		std::string getEffects() const;
		virtual ASpell * clone() const = 0;
		void launch(ATarget const & target) const;
	protected:
		std::string name;
		std::string effects;
};

#endif
