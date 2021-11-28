#include <iostream>
using namespace std;
class Number
{
private:
	int i;
public:
	Number( int x = 0 ) 
	{
		i = x;
		cout << "Constructor Number:" << i << endl;
	}
	~Number( ) { cout << "Destructor Number:" << i << endl; }
	Number operator+( const Number &x );
};
Number Number::operator+( const Number &x )
{
	Number result;
	cout << "Add Number" << endl;
	result.i = i + x.i;
	return result;
}
int main( )
{
	Number x(1), y(2);
	y = x + y;
	return 0;
}
