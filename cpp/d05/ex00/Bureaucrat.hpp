

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

namespace zob {

	class Bureaucrat {
	public:
		class GradeTooHighException : public std::exception {
		public:
			virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception {
		public:
			virtual const char *what() const throw();
		};

		Bureaucrat(std::string name, int grade)
			throw(GradeTooHighException, GradeTooLowException);
		Bureaucrat(Bureaucrat const &src);
		~Bureaucrat();

		Bureaucrat &operator=(Bureaucrat const &src);

		std::string getName() const;
		int getGrade() const;

		void incGrade() throw(GradeTooHighException);
		void decGrade() throw(GradeTooLowException);

	private:
		std::string const name;
		int grade;
	};
}

std::ostream &operator<<(std::ostream &o, zob::Bureaucrat const &rhs);

#endif
