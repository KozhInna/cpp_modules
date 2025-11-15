/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 11:09:41 by ikozhina          #+#    #+#             */
/*   Updated: 2025/11/15 11:32:17 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main(void)
{
    std::string str{"HI THIS IS BRAIN"};
    std::string* strPTR = &str;
    std::string& strREF = str;
    std::cout << "Addresses:" << std::endl;
    std::cout << &str << " - string" << std::endl;
    std::cout << strPTR << " - stringPTR" << std::endl;
    std::cout << &strREF << " - stringREF" << std::endl;
    std::cout << "Values:" << std::endl;
    std::cout << str << " - string" << std::endl;
    std::cout << *strPTR << " - stringPTR" << std::endl;
    std::cout << strREF << " - stringREF" << std::endl;

    return 0;
}
