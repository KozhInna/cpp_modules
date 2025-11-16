/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 19:50:47 by ikozhina          #+#    #+#             */
/*   Updated: 2025/11/16 21:35:09 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Weapon
{
    private:
        std::string type_;
        
    public:
        Weapon(const std::string& type);
        ~Weapon();
        const std::string& getType() const;
        void setType(const std::string& newType);
};
