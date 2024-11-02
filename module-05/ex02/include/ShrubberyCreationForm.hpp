/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coding_frog <coding_frog@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 18:43:56 by mde-cloe          #+#    #+#             */
/*   Updated: 2024/11/02 00:46:46 by coding_frog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"


#define ASCII_TREE "\n\t\t\t\t\t\t\t\t_,-/\"---, \n\
\t\t ;\"\"\"\"\"\"\"\"\"\";\t\t _/;; \"\"  <@`---v \n\
\t   ; :::::  ::  \"\\\t  _/ ;;  \"\t_.../ \n\
\t  ;\"\t ;;  ;;;  \\___/::\t;;,'\"\"\"\" \n\
\t ;\"\t\t  ;;;;.  ;;  ;;;  ::/ \n\
\t,/ / ;;  ;;;______;;;  ;;; ::,/ \n\
\t/;;V_;;   ;;;\t   \\\t   / \n\
\t| :/ / ,/\t\t\t\\_ \"\")/ \n\
\t| | / /\"\"\"=\t\t\t\\;;\"\"= \n\
\t; ;{::\"\"\"\"\"\"=\t\t\t\\\"\"\"= \n\
 ;\"\"\"\"\"; \n\
 \\/\"\"\" \n"

class ShrubberyCreationForm : public AForm
{
	public:
		// Constructors and Destructors
		ShrubberyCreationForm(void) = delete;
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &rhs);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);
		~ShrubberyCreationForm(void);

		// Public Methods
		void				execute(Bureaucrat const & executor) const override;
};
