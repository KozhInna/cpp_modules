/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 20:31:04 by ikozhina          #+#    #+#             */
/*   Updated: 2025/11/20 21:59:26 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include<string>

class Harl
{
    private:
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);    
    
    public:
        void complain(std::string level);        
};
