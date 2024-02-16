#ifndef FIXED_HPP
# define FIXED_HPP

# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define PURPLE "\033[1;35m"
# define RESET "\033[0m"

# include <cmath>
# include <iostream>

class Fixed
{
	private:
		static const int	bitStorage = 8;
		int					rawBits;
	public:
		Fixed();
		Fixed(const int integer);
		Fixed(const float floating);
		Fixed(const Fixed &fixed);
		Fixed &operator=(const Fixed &fixed);
		~Fixed();
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
};

std::ostream &operator<<(std::ostream &ostream, const Fixed &fixed);

#endif // FIXED_HPP
