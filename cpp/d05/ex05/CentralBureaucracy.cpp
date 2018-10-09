

#include "CentralBureaucracy.hpp"
#include <stdlib.h>

namespace zob {

	CentralBureaucracy::CentralBureaucracy() {
		for (unsigned i = 0; i < MAX_ACTION; ++i) actions[i] = NULL;
	}

	CentralBureaucracy::CentralBureaucracy(CentralBureaucracy const &src) {
		*this = src;
	}

	CentralBureaucracy::~CentralBureaucracy() {
		for (unsigned i = 0; i < MAX_ACTION; ++i)
			if (actions[i]) delete actions[i];
	}

	CentralBureaucracy &CentralBureaucracy::operator=(
		CentralBureaucracy const &src) {
		(void)src;
		return *this;
	}

	static Intern jack; // poor jack.. (it's a turfu clone)

	void CentralBureaucracy::feed(Bureaucrat &bureaucrat, int index) {
		if ((rand() % 2) == 0) offices[index].setSigner(bureaucrat);
		else offices[index].setExecutor(bureaucrat);
		offices[index].setIntern(jack);
	}

	void CentralBureaucracy::queueUp(std::string action) {
		unsigned i;

		for (i = 0; i < MAX_ACTION && actions[i]; ++i);
		if (i == MAX_ACTION)
			return;

		actions[i] = new std::string(action);
	}

	void CentralBureaucracy::doBureaucracy() {
		for (int i = MAX_ACTION - 1; i >= 0; --i) {
			std::string *t = actions[i];

			if (t) {
				actions[i] = NULL;

				for (unsigned j = 0; j < 20; ++j) {
					try {
						offices[j].doBureaucracy(*t, "Bender");
						goto next;

					} catch (std::exception &e) {
						std::cout << e.what() << std::endl;
					}
				}

				actions[i] = t;
			}
			next:;
		}
	}
}
