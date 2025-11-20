/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 20:31:02 by ikozhina          #+#    #+#             */
/*   Updated: 2025/11/20 21:57:31 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main ()
{
    Harl msg{};
    
    msg.complain("ERROR");
    msg.complain("DEBUG");
    msg.complain("WARNING");
    msg.complain("INFO");
    msg.complain("ERRO");
    
    return 0;
}