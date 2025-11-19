/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolos <lnicolos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 16:30:15 by lnicolos          #+#    #+#             */
/*   Updated: 2025/11/19 16:30:16 by lnicolos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include <iostream>

class Intern
{
    private:

    public:
        Intern();
        Intern(const Intern&);
        Intern& operator=(const Intern& other);
        ~Intern();

        AForm* makeForm(const std::string& formName, const std::string& formTarget);
};


#endif