#ifndef FIXED_HPP
# define FIXED_HPP

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define PURPLE "\033[0;35m"
#define BLUE "\033[0;34m"
#define YELLOW "\033[0;33m"
#define RESET "\033[0m"

# include <iostream>

class Fixed{
	private:
		static const int	bitStorage = 8;
		int					rawBits;
	public:
		Fixed();
		Fixed(const Fixed &fixed);
		Fixed &operator=(const Fixed &fixed);
		~Fixed();
		int	getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif
