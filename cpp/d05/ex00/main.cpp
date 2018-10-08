

#include <iostream>

#include "Bureaucrat.hpp"

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
	return 0;
}
