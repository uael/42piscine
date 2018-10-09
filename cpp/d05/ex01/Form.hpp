

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>

# include "Bureaucrat.hpp"

namespace zob {

	class Form {

	public:
		class GradeTooHighException : public std::exception {
		public:
			virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception {
		public:
			virtual const char *what() const throw();
		};

		Form(std::string name, int signGrade,
		     int execGrade) throw(GradeTooLowException, GradeTooHighException);
		Form(Form const &src);
		~Form();

		Form &operator=(Form const &src);

		void beSigned(Bureaucrat const &src) throw(GradeTooLowException);

		std::string const &getName() const;
		bool getSigned() const;
		int getSignRequiredGrade() const;
		int getExecRequiredGrade() const;

	private:
		const std::string name;
		bool sign;
		const int signRequiredGrade;
		const int execRequiredGrade;
	};
}

std::ostream &operator<<(std::ostream &o, zob::Form const &rhs);

#endif
