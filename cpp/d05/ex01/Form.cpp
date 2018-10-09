

#include "Form.hpp"

namespace zob {

	const char *Form::GradeTooHighException::what() const throw() {
		return "grade was too high";
	}

	const char *Form::GradeTooLowException::what() const throw() {
		return "grade was too low";
	}

	Form::Form(std::string name, int signGrade, int execGrade)
		throw(GradeTooHighException, GradeTooLowException)
		: name(name),
		  sign(false),
		  signRequiredGrade(signGrade),
		  execRequiredGrade(execGrade) {
		if (signRequiredGrade > 150 || execRequiredGrade > 150)
			throw Form::GradeTooLowException();
		if (signRequiredGrade < 1 || execRequiredGrade < 1)
			throw Form::GradeTooHighException();
	}

	Form::Form(Form const &src)
		: name(src.name),
		  sign(src.sign),
		  signRequiredGrade(src.signRequiredGrade),
		  execRequiredGrade(src.execRequiredGrade) {
		*this = src;
	}

	Form::~Form() { }

	Form &Form::operator=(Form const &src) {
		sign = src.sign;
		return *this;
	}

	void Form::beSigned(Bureaucrat const &src)
		throw(Form::GradeTooLowException) {
		if (src.getGrade() > signRequiredGrade)
			throw Form::GradeTooLowException();
		sign = true;
	}

	std::string const &Form::getName() const { return name; }

	bool Form::getSigned() const { return sign; }

	int Form::getSignRequiredGrade() const { return signRequiredGrade; }

	int Form::getExecRequiredGrade() const { return execRequiredGrade; }
}

std::ostream &operator<<(std::ostream &o, zob::Form const &rhs) {
	o << "Form " << rhs.getName()
	  << " (" << (rhs.getSigned() ? "signed" : "not signed") << ")"
	  << " sign grade: " << rhs.getSignRequiredGrade()
	  << ", exec grade: " << rhs.getExecRequiredGrade();
	return o;
}
