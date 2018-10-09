

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	try { zob::Bureaucrat b("Zob", 151); }
	catch (zob::Bureaucrat::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	}
	try { zob::Bureaucrat b("Zob", 0); }
	catch (zob::Bureaucrat::GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		zob::Bureaucrat b("Zob", 149);
		std::cout << "Hello " << b << std::endl;
		b.decGrade();
		std::cout << "Hello " << b << std::endl;
		b.decGrade();
	}
	catch (zob::Bureaucrat::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		zob::Bureaucrat b("Zob", 2);
		std::cout << "Hello " << b << std::endl;
		b.incGrade();
		std::cout << "Hello " << b << std::endl;
		b.incGrade();
	}
	catch (zob::Bureaucrat::GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
	}
	try { zob::Form f("4242", 150, 151); }
	catch (zob::Form::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	}
	try { zob::Form f("4242", 151, 150); }
	catch (zob::Form::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	}
	try { zob::Form f("4242", 1, 0); }
	catch (zob::Form::GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
	}
	try { zob::Form f("4242", 0, 1); }
	catch (zob::Form::GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		zob::Bureaucrat b("Zob", 2);
		zob::Form f("4242", 1, 1);

		std::cout << b << " want to sign " << f << std::endl;
		b.signForm(f);
	}
	catch (zob::Bureaucrat::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	}
	zob::Bureaucrat b("Zob", 1);
	zob::Form f("4242", 1, 1);

	std::cout << b << " want to sign " << f << std::endl;
	b.signForm(f);
	return 0;
}
