#include "whatever.hpp"


int main( void ) {
	char a = 'g';
	char b = 'z';
	
	::swap( a, b );
	
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	

	std::cout << '\n';
	std::string c = "chaine1";
	std::string d = "chaine2";
	
	::swap(c, d);
	
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;


	std::cout << '\n';
	int e = 234;
	int f = 245;
	
	::swap( e, f );
	
	std::cout << "e = " << e << ", f = " << f << std::endl;
	std::cout << "min( e, f ) = " << ::min( e, f ) << std::endl;
	std::cout << "max( e, f ) = " << ::max( e, f ) << std::endl;


	std::cout << '\n';
	float g = 235.1f;
	float h = 235.15f;
	
	::swap( g, h );
	
	std::cout << "g = " << g << ", h = " << h << std::endl;
	std::cout << "min( g, b ) = " << ::min( g, h ) << std::endl;
	std::cout << "max( g, b ) = " << ::max( g, h ) << std::endl;

	return 0;
}