#include "SpellBook.hpp"
		
SpellBook::SpellBook() {}

SpellBook::~SpellBook(){
	for (size_t i = 0; i < spells.size(); i++){
		delete(spells[i]);
	}
	spells.clear();
}

void SpellBook::learnSpell(ASpell * spell){
	for (size_t i = 0; i < spells.size(); i++){
		if (spell->getName() == spells[i]->getName()){
			return ;
		}
	}
	spells.push_back(spell->clone());
}

void SpellBook::forgetSpell(std::string const & spellName){
	for (size_t i = 0; i < spells.size(); i++){
		if (spellName == spells[i]->getName()){
			delete(spells[i]);
			spells.erase(spells.begin() + i);
			return ;
		}
	}
}

ASpell * SpellBook::createSpell(std::string const &spellName){
	for (size_t i = 0; i < spells.size(); i++){
		if (spellName == spells[i]->getName())
			return (spells[i]);
	}
	return NULL;
}



