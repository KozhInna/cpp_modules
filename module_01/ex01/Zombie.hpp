/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 13:41:12 by ikozhina          #+#    #+#             */
/*   Updated: 2025/11/15 10:36:47 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <string>

class Zombie
{
    private:
        std::string name;
    
    public:
        Zombie();
        Zombie(std::string zombieName);
        ~Zombie();
        void announce(void);
        void setName(std::string zombieName);
};

Zombie* zombieHorde(int N, std::string name);