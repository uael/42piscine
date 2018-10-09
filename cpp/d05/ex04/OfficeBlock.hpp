

#ifndef OFFICE_BLOCK_HPP
# define OFFICE_BLOCK_HPP

# include "Intern.hpp"
# include "Bureaucrat.hpp"

namespace zob {

	class OfficeBlock {

	public:
		class NoBureaucracyCanBeDoneException : public std::exception {
		public:
			virtual const char *what() const throw();
		};

		class NoTurfuCloneException : public std::exception {
		public:
			virtual const char *what() const throw();
		};

		OfficeBlock();
		OfficeBlock(Intern *intern, Bureaucrat *signer, Bureaucrat *executor);
		virtual ~OfficeBlock();

		void doBureaucracy(std::string formName, std::string target) const
			throw(NoBureaucracyCanBeDoneException,
						Intern::InvalidFormNameException,
						Form::GradeTooLowException);
		void setIntern(Intern &intern);
		void setSigner(Bureaucrat &signer);
		void setExecutor(Bureaucrat &executor);

	private:
		Intern *intern;
		Bureaucrat *signer, *executor;
	};
}

#endif
