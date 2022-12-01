#include "Warlock.hpp"
		
Warlock::Warlock(std::string const &name, std::string const &title) : name(name), title(title) {
	std::cout << name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock(){
	std::cout << name << ": My job here is done!" << std::endl;
	for (size_t i = 0; i < spells.size(); i++){
		delete(spells[i]);
	}
	spells.clear();
}

std::string const & Warlock::getName() const {return name;}
std::string const & Warlock::getTitle() const {return title;}
void Warlock::setTitle(std::string const &title){this->title = title;}
void Warlock::introduce() const {
	std::cout << name << ": I am " << name << ", "<< title << "!" << std::endl;
}

Warlock::Warlock(Warlock const & src) {*this = src;}
Warlock & Warlock::operator=(Warlock const & src){this->name = src.name; this-> title=src.title; return *this;}

void Warlock::learnSpell(ASpell * spell){
	for (size_t i = 0; i < spells.size(); i++){
		if (spell->getName() == spells[i]->getName()){
			return ;
		}
	}
	spells.push_back(spell->clone());
}

void Warlock::forgetSpell(std::string spellName){
	for (size_t i = 0; i < spells.size(); i++){
		if (spellName == spells[i]->getName()){
			delete(spells[i]);
			spells.erase(spells.begin() + i);
			return ;
		}
	}
}

void Warlock::launchSpell(std::string spellName, ATarget const & target){
	for (size_t i = 0; i < spells.size(); i++){
		if (spellName == spells[i]->getName()){
			return spells[i]->launch(target);
		}
	}
}


