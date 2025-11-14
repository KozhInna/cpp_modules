/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 13:41:12 by ikozhina          #+#    #+#             */
/*   Updated: 2025/11/14 13:30:54 by ikozhina         ###   ########.fr       */
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
        Zombie(const Zombie& other);
        Zombie& operator=(const Zombie& other);
        ~Zombie();
        
        void announce(void);
        void setName(std::string zombieName);
};

Zombie* zombieHorde(int N, std::string name);