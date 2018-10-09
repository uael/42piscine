

#include "OfficeBlock.hpp"

namespace zob {

	const char *OfficeBlock::NoBureaucracyCanBeDoneException::what() const
		throw() {
		return "no bureaucracy can be done";
	}

	const char *OfficeBlock::NoTurfuCloneException::what() const
		throw() {
		return "turfu clone are not acceptable";
	}

	OfficeBlock::OfficeBlock()
		: intern(NULL), signer(NULL), executor(NULL) { }

	OfficeBlock::OfficeBlock(Intern *intern, Bureaucrat *signer,
	                         Bureaucrat *executor)
	  : intern(intern), signer(signer), executor(executor) { }

	OfficeBlock::~OfficeBlock() { }

	void OfficeBlock::doBureaucracy(std::string formName,
	                                std::string target) const
	  throw(NoBureaucracyCanBeDoneException, Intern::InvalidFormNameException,
	  	    Form::GradeTooLowException) {
		Form *f;

		if (!intern || !signer || !executor)
			throw NoBureaucracyCanBeDoneException();
		f = intern->makeForm(formName, target);
		signer->signForm(*f);
		executor->executeForm(*f);
		delete f;
	}

	void OfficeBlock::setIntern(Intern &intern) {
		this->intern = &intern;
	}

	void OfficeBlock::setSigner(Bureaucrat &signer) {
		if (executor == &signer) throw NoTurfuCloneException();
		this->signer = &signer;
	}

	void OfficeBlock::setExecutor(Bureaucrat &executor) {
		if (signer == &executor) throw NoTurfuCloneException();
		this->executor = &executor;
	}
}
