
#include <string>
#include <iostream>

#include "ATarget.hpp"
#include <vector>

class TargetGenerator
{
	public:
		TargetGenerator();
		~TargetGenerator();
	
		void learnTargetType(ATarget *newTarget);
		void forgetTargetType(std::string const & targetName);
		ATarget * createTarget(std::string const & targetName);
	private:
		TargetGenerator(TargetGenerator const & other);
		TargetGenerator& operator=(TargetGenerator const & other);
	
		std::vector<ATarget *> targets;
};

