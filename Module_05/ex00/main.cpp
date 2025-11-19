/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolos <lnicolos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 16:28:53 by lnicolos          #+#    #+#             */
/*   Updated: 2025/11/19 16:28:54 by lnicolos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    try
    {
        std::cout << std::endl << "Try to increment grade : " << std::endl;
        Bureaucrat b("Henry", 10);
        for (int i = 0; i < 9; i++)
        {
            b.incrementGrade();
            std::cout << b << std::endl;
        }
        std::cout << "all good until now that we increment again : " << std::endl;
        b.incrementGrade();
        std::cout << b << std::endl; //ne saffiche pas car avant l'exception se declanche
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl << "==========================================" << std::endl;
    try
    {
        std::cout << std::endl << "Try to decrement grade : " << std::endl;
        Bureaucrat c("Juliette", 140);
        for (int i = 0; i < 10; i++)
        {
            c.decrementGrade();
            std::cout << c << std::endl;
        }
        std::cout << "all good until now that we decrement again : " << std::endl;
        c.decrementGrade();
        std::cout << c << std::endl; //ne saffiche pas car avant l'exception se declanche
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    
    
    return 0;
}