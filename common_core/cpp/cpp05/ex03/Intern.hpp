/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:52:46 by kyubongchoi       #+#    #+#             */
/*   Updated: 2023/01/06 15:02:16 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN
# define INTERN

# include "Bureaucrat.hpp"
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern {
	public:
		Intern();
		Intern(const Intern &inst);
		~Intern();
		Intern &operator=(const Intern &rhs);

		/* exception */
		class NoExistForm: public std::exception {
			virtual const char* what() const throw();
		};

		AForm *makeForm(const std::string name, const std::string target);
};

#endif