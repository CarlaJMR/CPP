/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:31:35 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/01/19 18:29:16 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include <iostream>
#include <iomanip>

class Contact
{
    public:
        Contact(void);
        ~Contact(void);
        
    private:
        std::string first;
        std::string last;
        std::string nick;
        std::string phone;
        std::string secret;   
};

class PhoneBook
{
    public:
        int nb_cont;
        int last_cont;
        PhoneBook(void);
        ~PhoneBook(void);
    private:
        Contact list[8];
        void    _AddContact();
        void    _SearchContact(void) const;
};

#endif
