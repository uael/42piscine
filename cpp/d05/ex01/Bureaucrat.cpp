

#include "Bureaucrat.hpp"
#include "Form.hpp"

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

	Bureaucrat::Bureaucrat(Bureaucrat const &src)
		: name(src.name) { *this = src; }

	Bureaucrat::~Bureaucrat() { }

	Bureaucrat &Bureaucrat::operator=(Bureaucrat const &src) {
		grade = src.grade;
		return *this;
	}

	void Bureaucrat::signForm(Form &form) const {
		try {
			form.beSigned(*this);
			std::cout << *this << " signs form " << form.getName() << std::endl;
		} catch (Form::GradeTooLowException &e) {
			std::cout << *this << " cannot sign form " << form.getName()
			          << " because " << e.what() << std::endl;
		}
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
