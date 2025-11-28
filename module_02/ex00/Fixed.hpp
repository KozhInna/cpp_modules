/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 12:03:56 by ikozhina          #+#    #+#             */
/*   Updated: 2025/11/28 10:14:59 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Fixed {
	private:
		int rawValue_;
		static const int frBits = 8;

	public:
		Fixed();	//default constructor
		~Fixed();	// destructor
		Fixed(const Fixed& other); //copy constuctor
		Fixed& operator=(const Fixed& other); //copy assignment operator

		int getRawBits(void) const;
		void setRawBits(int const raw);
};