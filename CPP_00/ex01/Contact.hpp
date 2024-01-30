/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:31:35 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/01/30 16:20:48 by cjoao-me         ###   ########.fr       */
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
        Contact(void);
        ~Contact(void);
        
    private:
        std::string _first;
        std::string _last;
        std::string _nick;
        std::string _phone;
        std::string _secret;
        Contact    _newcontact();
        void       _printcontactline(void) const;
        void       _printcontactinfo(void) const;      
};

#endif
