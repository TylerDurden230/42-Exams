
#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() { }

TargetGenerator::~TargetGenerator()
{
	for (int i = 0; i < targets.size(); i++)
		delete(targets[i]);
	targets.clear();
}

void TargetGenerator::learnTargetType(ATarget *newTarget)
{
	for (int i = 0; i < targets.size(); i++)
	{
		if (newTarget->getType() == targets[i]->getType())
			return ;
	}
	targets.push_back(newTarget->clone());
}

void TargetGenerator::forgetTargetType(std::string const & targetName)
{
	for (int i = 0; i < targets.size(); i++)
	{
		if (targetName == targets[i]->getType())
		{
			delete(targets[i]);
			targets.erase(targets.begin() + i);
			return ;
		}
	}
}

ATarget * TargetGenerator::createTarget(std::string const & targetName)
{
	for (int i = 0; i < targets.size(); i++)
	{
		if (targetName == targets[i]->getType())
			return (targets[i]);
	}
	return (nullptr);
}


