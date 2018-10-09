

#include "Intern.hpp"

namespace zob {

	const char *Intern::InvalidFormNameException::what() const throw() {
		return "name was invalid";
	}

	Intern::Intern() { }

	Intern::Intern(Intern const &src) { *this = src; }

	Intern::~Intern() { }

	Intern &Intern::operator=(Intern const &src) {
		(void)src;
		return *this;
	}

	Form *Intern::makeForm(std::string const name, std::string const target)
		const {
		Form *form;

		if (name == "presidential pardon")
			form = new PresidentialPardonForm(target);
		else if (name == "robotomy request")
			form = new RobotomyRequestForm(target);
		else if (name == "shrubbery creation")
			form = new ShrubberyCreationForm(target);
		else {
			std::cout << "Unknown form name master, dunno how to make it..";
			return NULL;
		}

		std::cout << "Intern creates " << *form << std::endl;
		return form;
	}
}
