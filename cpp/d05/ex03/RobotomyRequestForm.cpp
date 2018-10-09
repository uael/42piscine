

#include <cstdlib>

#include "RobotomyRequestForm.hpp"

namespace zob {

	RobotomyRequestForm::RobotomyRequestForm(std::string target)
		: Form(target, 72, 45) { }

	RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src)
		: Form(src) { }

	RobotomyRequestForm::~RobotomyRequestForm() { }

	RobotomyRequestForm &RobotomyRequestForm::operator=(
		RobotomyRequestForm const &src) {
		Form::operator=(src);
		return *this;
	}

	void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
		Form::execute(executor);

		std::cout << "Some drilling noises.." << std::endl;
		if ((rand() % 2) == 0)
			std::cout << getName() << " has been robotomized successfully."
			          << std::endl;
		else
			std::cout << getName() << " has been failed." << std::endl;
	}
}
