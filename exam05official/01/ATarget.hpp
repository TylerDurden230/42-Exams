
#ifndef ATARGET_HPP
# define ATARGET_HPP

#include <string>
#include <iostream>

#include "ASpell.hpp"

class ATarget
{
	public:
		ATarget();
		ATarget(std::string type);
		ATarget(ATarget const & other);
		ATarget& operator=(ATarget const & other);
		virtual ~ATarget();

		std::string const & getType() const;
		virtual ATarget * clone() const = 0;
		void getHitBySpell(ASpell const & spell) const;
	protected:
		std::string type;
};

#endif
