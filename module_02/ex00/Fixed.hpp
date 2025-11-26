/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 12:03:56 by ikozhina          #+#    #+#             */
/*   Updated: 2025/11/26 13:06:41 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Fixed {
    private:
        int value_;
        static const int frBits = 8;
        
    public:
        Fixed();
        ~Fixed();
        Fixed(const Fixed& other); 
        Fixed& operator=(const Fixed& other);
        
        int getRawBits(void) const;
        void setRawBits(int const raw);       
};