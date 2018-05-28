/*************************************************************************
 ** Program File Name: MinMax
 ** Author: Stephanie Babb
 ** Date: 1/12/17
 ** Description: Uses climits and cmath libraries to find the maximum and
  *  minimum possible signed/unsigned ints, longs, shorts, and numbers in a byte
 ** Input: User input of a whole number
 ** Output: The maximum and minimum signed and unsigned ints, longs, shorts,
  *  numbers in a byte, and numbers in the user defined number of bits and
  *  the strings that describe them
**************************************************************************/
#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

int main(){
	cout << "Minimum signed int: " << INT_MIN << endl;
	cout << "Maximum signed int: " << INT_MAX << endl;
	cout << "Minimum unsigned int: " << 0 << endl;
	cout << "Maximum unsigned int: " << UINT_MAX << endl;
	cout << "Minimum signed long: " << LONG_MIN << endl;
	cout << "Maximum signed long: " << LONG_MAX << endl;
	cout << "Minimum unsigned long: " << 0 << endl;
	cout << "Maximum unsinged long: " << ULONG_MAX << endl;
	cout << "Minimum signed short: " << SHRT_MIN << endl;
	cout << "Maximum signed short: " << SHRT_MAX << endl;
	cout << "Minimum unsigned short: " << 0 << endl;
	cout << "Maximum unsigned short: " << USHRT_MAX << endl;	
	
	cout << "Maximum numer in a signed byte: " << pow(2, 8-1)-1 << endl;
	cout << "Minimum number in a signed byte: " << -1*pow(2, 8-1) << endl;
	cout << "Maximum number in an unsigned byte: " << pow(2, 8)-1 << endl;
	
	int byteSz;

	cout << "Enter a whole number: ";
	cin >> byteSz;
	cout << "Maximum number with " << byteSz << " signed bits: " << pow(2, byteSz-1)-1 << endl;
	cout << "Minimum number with " << byteSz << " signed bits: " << -1*pow(2, byteSz-1) << endl;
	cout << "Maximum number with " << byteSz << " unsigned bits: " << pow(2, byteSz)-1 << endl;

	return 0;
}
