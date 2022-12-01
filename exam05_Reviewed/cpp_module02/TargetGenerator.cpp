#include "TargetGenerator.hpp"
		
TargetGenerator::TargetGenerator() {}

TargetGenerator::~TargetGenerator(){
	for (size_t i = 0; i < targets.size(); i++){
		delete(targets[i]);
	}
	targets.clear();
}

void TargetGenerator::learnTargetType(ATarget * spell){
	for (size_t i = 0; i < targets.size(); i++){
		if (spell->getType() == targets[i]->getType()){
			return ;
		}
	}
	targets.push_back(spell->clone());
}

void TargetGenerator::forgetTargetType(std::string const & TargetType){
	for (size_t i = 0; i < targets.size(); i++){
		if (TargetType == targets[i]->getType()){
			delete(targets[i]);
			targets.erase(targets.begin() + i);
			return ;
		}
	}
}

ATarget * TargetGenerator::createTarget(std::string const &TargetType){
	for (size_t i = 0; i < targets.size(); i++){
		if (TargetType == targets[i]->getType())
			return (targets[i]);
	}
	return NULL;
}



