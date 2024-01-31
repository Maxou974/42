#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("tree", 137, 145)
{
	_target = "target";
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(target, 137, 145)
{
	_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &ref) : AForm(ref)
{
	_target = ref._target;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm &ref)
{
	AForm::operator=(ref);
	_target = ref._target;
	return *this;
}

void	ShrubberyCreationForm::execute(const Bureaucrat & executor) const{
	check_exec(executor);
	std::ofstream ofs;
	std::string namefile = _target + "_shrubbery";
	ofs.open(namefile.c_str(), std::ofstream::out);
	if (ofs.is_open())
	{
		ofs << "	          .     .  .      +     .      .          .			\n";
		ofs << "     .       .      .     #       .           .\n";
		ofs << "        .      .         ###            .      .      .\n";
		ofs << "      .      .   \"#:. .:##\"##:. .:#\"  .      .\n";
		ofs << "          .      . \"####\"###\"####\"  .\n";
		ofs << "       .     \"#:.    .:#\"###\"#:.    .:#\"  .        .       .\n";
		ofs << "  .             \"#########\"#########\"        .        .\n";
		ofs << "        .    \"#:.  \"####\"###\"####\"  .:#\"   .       .\n";
		ofs << "     .     .  \"#######\"\"##\"##\"\"#######\"                  .\n";
		ofs << "                .\"##\"#####\"#####\"##\"           .      .\n";
		ofs << "    .   \"#:. ...  .:##\"###\"###\"##:.  ... .:#\"     .\n";
		ofs << "      .     \"#######\"##\"#####\"##\"#######\"      .     .\n";
		ofs << "    .    .     \"#####\"\"#######\"\"#####\"    .      .\n";
		ofs << "            .     \"      000      \"    .     .\n";
		ofs << "       .         .   .   000     .        .       .\n";
		ofs << ".. .. ..................O000O........................ ...... ...\n";
		ofs.close();
	}
	else
		std::cout << "Couldnt open file\n";
}