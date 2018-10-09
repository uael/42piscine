

#include "ShrubberyCreationForm.hpp"

#include <fstream>

namespace zob {

	ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
		: Form(target, 145, 137) { }

	ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src)
		: Form(src) { }

	ShrubberyCreationForm::~ShrubberyCreationForm() { }

	ShrubberyCreationForm &ShrubberyCreationForm::operator=(
		ShrubberyCreationForm const &src) {
		Form::operator=(src);
		return *this;
	}

	void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
		Form::execute(executor);
		std::ofstream ofs((getName() + "_shrubbery").c_str());

		if (ofs.is_open()) {

			ofs << "               ,@@@@@@@,\n"
			       "       ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
			       "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n"
			       "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n"
			       "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n"
			       "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n"
			       "   `&%\\ ` /%&'    |.|        \\ '|8'\n"
			       "       |o|        | |         | |\n"
			       "       |.|        | |         | |\n"
			       "jgs \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_" << std::endl;
			ofs.close();
		}
	}
}
