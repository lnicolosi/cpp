/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolos <lnicolos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 16:28:39 by lnicolos          #+#    #+#             */
/*   Updated: 2025/11/19 16:28:40 by lnicolos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    try
    {
        // Bureaucrat b("Henry", 100);
         Form f("b12", 102, 105);
        // b.signForm(f);
        // std::cout << std::endl;
        // b.signForm(f);
        std::cout << f << std::endl;
        Bureaucrat c("Giorgia", 120);
        c.signForm(f);
        std::cout << std::endl;
        Bureaucrat d("Cristiana", 10);
        d.signForm(f);


    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    
    
    return 0;
}