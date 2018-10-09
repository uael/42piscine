

#ifndef INTERN_HPP
# define INTERN_HPP

# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"

namespace zob {

	class Intern {
	public:
		class InvalidFormNameException : public std::exception {
		public:
			virtual const char *what() const throw();
		};

		Intern();
		Intern(Intern const &src);
		~Intern();

		Intern &operator=(Intern const &src);

		Form *makeForm(std::string name, std::string target) const;
	};
}

#endif
