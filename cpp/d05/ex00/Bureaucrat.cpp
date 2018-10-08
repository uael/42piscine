

#include "Bureaucrat.hpp"

namespace zob {

	const char *Bureaucrat::GradeTooHighException::what() const throw() {
		return "Grade was too high";
	}

	const char *Bureaucrat::GradeTooLowException::what() const throw() {
		return "Grade was too low";
	}

	Bureaucrat::Bureaucrat(std::string name, int grade)
		throw(GradeTooHighException, GradeTooLowException)
		: name(name), grade(grade) {
		if (grade > 150) throw Bureaucrat::GradeTooLowException();
		if (grade < 1) throw Bureaucrat::GradeTooHighException();
	}

	Bureaucrat::Bureaucrat(Bureaucrat const &src) { *this = src; }

	Bureaucrat::~Bureaucrat() { }

	Bureaucrat &Bureaucrat::operator=(Bureaucrat const &src) {
		this->grade = src.grade;
		return *this;
	}

	void Bureaucrat::incGrade() throw(GradeTooHighException) {
		if (grade - 1 < 1)
			throw Bureaucrat::GradeTooHighException();
		--grade;
	}

	void Bureaucrat::decGrade() throw(GradeTooLowException) {
		if (grade + 1 > 150)
			throw Bureaucrat::GradeTooLowException();
		++grade;
	}

	std::string Bureaucrat::getName() const { return name; }

	int Bureaucrat::getGrade() const { return grade; }
}

std::ostream &operator<<(std::ostream &o, zob::Bureaucrat const &rhs) {
	o << rhs.getName() << " (" << rhs.getGrade() << ")";
	return o;
}
