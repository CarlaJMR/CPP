/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:31:35 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/02/01 15:42:43 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>
#include <iomanip>

class Contact
{
    public:
        Contact();
        ~Contact(void);
        void    printcontactline(void) const;
        void    printsinglecontact(void) const;
        void    newcontact(std::string first, std::string last, std::string nick, std::string phone, std::string secret);
        
    private:
        std::string _first;
        std::string _last;
        std::string _nick;
        std::string _phone;
        std::string _secret;     
};

#endif
