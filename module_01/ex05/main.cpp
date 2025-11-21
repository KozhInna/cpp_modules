/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 20:31:02 by ikozhina          #+#    #+#             */
/*   Updated: 2025/11/21 09:37:55 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main (void)
{
	Harl msg{};

	msg.complain("ERROR");
	msg.complain("DEBUG");
	msg.complain("WARNING");
	msg.complain("INFO");
	msg.complain("ERRO");

	return 0;
}