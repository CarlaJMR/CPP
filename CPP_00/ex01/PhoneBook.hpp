/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:31:35 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/02/06 10:51:25 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
    public:
       
        PhoneBook(void);
        ~PhoneBook(void);
        void    AddContact();
        void    SearchContact(void) const;
      
    private:
        int _nb_cont;
        int _next_cont;
        Contact _list[8];
        //std::string		_get_field_contact(std::string field, std::string prompt);
};

#endif
