

#include "PresidentialPardonForm.hpp"

namespace zob {

	PresidentialPardonForm::PresidentialPardonForm(std::string target)
		: Form(target, 25, 5) { }

	PresidentialPardonForm::PresidentialPardonForm(
		PresidentialPardonForm const &src)
			: Form(src) { }

	PresidentialPardonForm::~PresidentialPardonForm() { }

	PresidentialPardonForm & PresidentialPardonForm::operator=(
		PresidentialPardonForm const &src) {
		Form::operator=(src);
		return *this;
	}

	void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
		Form::execute(executor);
		std::cout << getName() << " has been pardoned by Zafod Beeblebrox."
		          << std::endl;
	}
}
