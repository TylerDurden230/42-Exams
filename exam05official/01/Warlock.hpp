
#include <string>
#include <iostream>

#include "ASpell.hpp"
#include "ATarget.hpp"
#include <vector>

class Warlock
{
	public:
		Warlock(std::string name, std::string title);
		~Warlock();

		std::string const & getName() const;
		std::string const & getTitle() const;
		void	setTitle(std::string const & title);

		void introduce() const;
		void learnSpell(ASpell *newSpell);
		void forgetSpell(std::string spellName);
		void launchSpell(std::string spellName, ATarget& target);
	private:
		Warlock();
		Warlock(Warlock const & other);
		Warlock& operator=(Warlock const & other);

		std::string name;
		std::string title;
		std::vector<ASpell *> spells;
};

