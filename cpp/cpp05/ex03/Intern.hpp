/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:52:46 by kyubongchoi       #+#    #+#             */
/*   Updated: 2022/09/02 18:19:35 by kyubongchoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN
# define INTERN

# include "Bureaucrat.hpp"
# include "Form.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern {
	private:
		typedef Form* (*func)(const std::string target);
		typedef struct {
			std::string _name;
			func _func;
		} FormList;
	public:
		Intern();
		Intern(const Intern &inst);
		~Intern();
		Intern &operator=(const Intern &rhs);

		/* exception */
		class NoExistForm: public std::exception {
			virtual const char* what() const throw();
		};

		Form *makeForm(const std::string name, const std::string target);
};

#endif