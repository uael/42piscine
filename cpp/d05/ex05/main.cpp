

#include <cstdlib>

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
#include "OfficeBlock.hpp"
#include "CentralBureaucracy.hpp"

int main() {
	zob::CentralBureaucracy cb;
	static zob::Bureaucrat bs[20] = {
		zob::Bureaucrat("1", 1),
		zob::Bureaucrat("2", 2),
		zob::Bureaucrat("3", 3),
		zob::Bureaucrat("4", 4),
		zob::Bureaucrat("5", 5),
		zob::Bureaucrat("6", 6),
		zob::Bureaucrat("7", 7),
		zob::Bureaucrat("8", 8),
		zob::Bureaucrat("9", 9),
		zob::Bureaucrat("10", 10),
		zob::Bureaucrat("11", 11),
		zob::Bureaucrat("12", 12),
		zob::Bureaucrat("13", 13),
		zob::Bureaucrat("14", 14),
		zob::Bureaucrat("15", 15),
		zob::Bureaucrat("16", 16),
		zob::Bureaucrat("17", 17),
		zob::Bureaucrat("18", 18),
		zob::Bureaucrat("19", 19),
		zob::Bureaucrat("20", 20),
	};

	for (unsigned i = 0; i < 20; ++i) {
		retry:
		try {
			cb.feed(bs[i], rand() % 20);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
			goto retry;
		}
	}
	for (unsigned i = 0; i < 20; ++i) {
		retry1:
		try {
			cb.feed(bs[i], rand() % 20);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
			goto retry1;
		}
	}

	cb.queueUp("presidential pardon");
	cb.queueUp("robotomy request");
	cb.queueUp("shrubbery creation");
	cb.queueUp("presidential pardon");
	cb.queueUp("robotomy request");
	cb.queueUp("shrubbery creation");
	cb.queueUp("presidential pardon");
	cb.queueUp("robotomy request");
	cb.queueUp("shrubbery creation");
	cb.queueUp("presidential pardon");
	cb.queueUp("robotomy request");
	cb.queueUp("shrubbery creation");
	cb.queueUp("presidential pardon");
	cb.queueUp("robotomy request");
	cb.queueUp("shrubbery creation");
	cb.queueUp("presidential pardon");
	cb.queueUp("robotomy request");
	cb.queueUp("shrubbery creation");
	cb.queueUp("presidential pardon");
	cb.queueUp("robotomy request");
	cb.queueUp("shrubbery creation");
	cb.queueUp("presidential pardon");
	cb.queueUp("robotomy request");
	cb.queueUp("shrubbery creation");
	cb.queueUp("presidential pardon");
	cb.queueUp("robotomy request");
	cb.queueUp("shrubbery creation");
	cb.queueUp("presidential pardon");
	cb.queueUp("robotomy request");
	cb.queueUp("shrubbery creation");
	cb.queueUp("presidential pardon");
	cb.queueUp("robotomy request");
	cb.queueUp("shrubbery creation");
	cb.queueUp("presidential pardon");
	cb.queueUp("robotomy request");
	cb.queueUp("shrubbery creation");
	cb.queueUp("presidential pardon");
	cb.queueUp("robotomy request");
	cb.queueUp("shrubbery creation");
	cb.queueUp("presidential pardon");
	cb.queueUp("robotomy request");
	cb.queueUp("shrubbery creation");
	cb.queueUp("presidential pardon");
	cb.queueUp("robotomy request");
	cb.queueUp("shrubbery creation");
	cb.queueUp("presidential pardon");

	cb.doBureaucracy();
	return 0;
}
