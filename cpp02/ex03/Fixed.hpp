#ifndef FIXED_HPP
# define FIXED_HPP

# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define CYAN "\033[1;36m"
# define BOLD_UNDERLINE "\033[1;4m"
# define PURPLE "\033[1;35m"
# define RESET "\033[0m"

# include <iostream>

class Fixed
{
	private:
			static const int	bitStorage = 8;
			int					rawBits;

	public:
		Fixed( void );
		Fixed( const int n );
		Fixed( const float n );
		Fixed( const Fixed &fixed );
		Fixed& operator=( const Fixed &fixed );
		~Fixed();

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;

		bool	operator>( const Fixed &fixed ) const ;
		bool	operator<( const Fixed &fixed ) const ;
		bool	operator>=( const Fixed &fixed ) const ;
		bool	operator<=( const Fixed &fixed ) const ;
		bool	operator==( const Fixed &fixed ) const ;
		bool	operator!=( const Fixed &fixed ) const ;

		Fixed	operator+( const Fixed &fixed ) const ;
		Fixed	operator-( const Fixed &fixed ) const ;
		Fixed	operator*( const Fixed &fixed ) const ;
		Fixed	operator/( const Fixed &fixed ) const ;

		Fixed&	operator++( void );
		Fixed	operator++( int );
		Fixed&	operator--( void );
		Fixed	operator--( int );

		static Fixed&		min( Fixed &a, Fixed &b );
		static Fixed&		max( Fixed &a, Fixed &b );
		static const Fixed&	min( const Fixed &a, const Fixed &b );
		static const Fixed&	max( const Fixed &a, const Fixed &b );
};

std::ostream & operator<<( std::ostream & ostream, Fixed const & i );

#endif // FIXED_HPP
