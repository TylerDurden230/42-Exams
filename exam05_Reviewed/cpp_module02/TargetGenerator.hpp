#pragma once

#include <iostream>
#include "ATarget.hpp"
#include "ASpell.hpp"
#include <vector>

class TargetGenerator {
	public:
		TargetGenerator();
		~TargetGenerator();

		void learnTargetType(ATarget * target);
		void forgetTargetType(std::string const & targetName);
		ATarget * createTarget(std::string const & targetName);

	private:
		TargetGenerator(TargetGenerator const & src);
		TargetGenerator & operator=(TargetGenerator const & src);
		std::vector<ATarget *> targets;
};
