#pragma once

#include "ASpell.hpp"
#include <iostream>


class ATarget {
	public:
		ATarget();
		ATarget(std::string const &type);
		virtual ~ATarget();
		ATarget(ATarget const & src);
		ATarget & operator=(ATarget const & src);
		std::string const & getType() const;
		virtual ATarget * clone() const = 0;
		void getHitBySpell(ASpell const & spell) const;

	protected:
		std::string type;
};
