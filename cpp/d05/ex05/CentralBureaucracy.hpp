

#ifndef CENTRAL_BUREAUCRACY_HPP
# define CENTRAL_BUREAUCRACY_HPP

# include "Bureaucrat.hpp"
# include "OfficeBlock.hpp"

# define MAX_ACTION 64

namespace zob {

	class CentralBureaucracy {
	public:
		CentralBureaucracy();
		CentralBureaucracy(CentralBureaucracy const &src);
		~CentralBureaucracy();

		CentralBureaucracy &operator=(CentralBureaucracy const &src);

		void feed(Bureaucrat &bureaucrat, int index);
		void queueUp(std::string action);
		void doBureaucracy();

	private:
		OfficeBlock offices[20];
		std::string *actions[MAX_ACTION];
	};
}

#endif
