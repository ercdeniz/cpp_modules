#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm::AForm("shrubbery creation", 145, 137), _target("Default") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm::AForm("shrubbery creation", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) :  AForm::AForm("shrubbery creation", 145, 137) {
    *this = copy;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy) {
    if (this != &copy)
        _target = copy._target;
    return *this;
}

void ShrubberyCreationForm::specificExecute(void) const {
    std::ofstream o((_target + ".shrubbery").c_str());

    o << "                                                         .\n"
    << "                                              .         ;  \n"
    << "                 .              .              ;%     ;;   \n"
    << "                   ,           ,                :;%  %;   \n"
    << "                    :         ;                   :;%;'     .,   \n"
    << "           ,.        %;     %;            ;        %;'    ,;\n"
    << "             ;       ;%;  %%;        ,     %;    ;%;    ,%'\n"
    << "              %;       %;%;      ,  ;       %;  ;%;   ,%;' \n"
    << "               ;%;      %;        ;%;        % ;%;  ,%;'\n"
    << "                `%;.     ;%;     %;'         `;%%;.%;'\n"
    << "                 `:;%.    ;%%. %@;        %; ;@%;%'\n"
    << "                    `:%;.  :;bd%;          %;@%;'\n"
    << "                      `@%:.  :;%.         ;@@%;'   \n"
    << "                        `@%.  `;@%.      ;@@%;         \n"
    << "                          `@%%. `@%%    ;@@%;        \n"
    << "                            ;@%. :@%%  %@@%;       \n"
    << "                              %@bd%%%bd%%:;     \n"
    << "                                #@%%%%%:;;\n"
    << "                                %@@%%%::;\n"
    << "                                %@@@%(o);  . '         \n"
    << "                                %@@@o%;:(.,'         \n"
    << "                            `.. %@@@o%::;         \n"
    << "                               `)@@@o%::;         \n"
    << "                                %@@(o)::;        \n"
    << "                               .%@@@@%::;         \n"
    << "                               ;%@@@@%::;.          \n"
    << "                              ;%@@@@%%:;;;. \n"
    << "                          ...;%@@@@@%%:;;;;,..  \n";
    o.close();
    std::cout << GREEN << "File generated: " I_BLUE << _target << ".shrubbery" << RESET << std::endl;
}
