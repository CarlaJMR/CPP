/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:31:35 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/02/16 14:54:45 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>

void myReplace (std::string &content, std::string s1, std::string s2)
{
  int i = -1;
  while ((i = content.find(s1, i + 1)) != std::string::npos)
  {
    content.erase(i, s1.size());
    content.insert(i, s2);
  }
}

void getContent(std::ifstream &ifs, std::string &content)
{
  char ch;

  while (ifs.get(ch)) 
    content.push_back(ch);
  ifs.close();
}

int main(int ac, char **av)
{
  
  if (ac == 4)
  {
    std::string	filename = av[1];
		std::string	s1 = av[2];
		std::string	s2 = av[3];
  
    if (filename.empty() || s1.empty() || s2.empty())
    {
      std::cout << "Empty argument(s)!"<< std::endl;
      return(1);
    }
    std::string	content;
    
    std::ifstream ifs (filename);
    
    if (!ifs)
    {
        std::cout << "Error opening file: " << filename << std::endl;
        return(1);
    }
    getContent(ifs, content);
    myReplace(content, s1, s2);
    std::ofstream ofs ((filename.append(".replace")));
    if (!ofs)
		  std::cout << "Error creating file: " << filename + ".replace" << std::endl;
	  else
    {
      ofs << content;
      ofs.close();
    }
	}
	else
    std::cout << "Wrong number of arguments!" << std::endl;
  return 0;
}

