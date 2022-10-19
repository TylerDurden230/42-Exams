
#include <string>
#include <iostream>

class Warlock
{
	public:
		Warlock(std::string name, std::string title);
		~Warlock();

		std::string const & getName() const;
		std::string const & getTitle() const;
		void	setTitle(std::string const & title);

		void introduce() const;
	private:
		Warlock();
		Warlock(Warlock const & other);
		Warlock& operator=(Warlock const & other);

		std::string name;
		std::string title;
};

