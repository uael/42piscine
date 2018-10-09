

#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP

# include "Form.hpp"

namespace zob {

	class RobotomyRequestForm : public Form {
	public:
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm const &src);
		~RobotomyRequestForm();

		RobotomyRequestForm &operator=(RobotomyRequestForm const &src);

		virtual void execute(Bureaucrat const &executor) const;
	};
}

#endif
