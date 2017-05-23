// Phillip Benoit
// CIS269
// Homework 2
// Poly.h - Polynomial class

#ifndef __POLY_H__
#define __POLY_H__

#include "stdio.h"

template <class T>
class Poly
{
public:
	T first, second, third;
	Poly(T a, T b, T c);
	void print();
	void add(Poly addend);
	void multiply(Poly multiplier);
};

#endif // __POLY_H__

template<class T>
inline Poly<T>::Poly(T a, T b, T c)
{
	first = a;
	second = b;
	third = c;
}

template<class T>
inline void Poly<T>::print()
{
	printf("(%d)x%c + (%d)x + (%d)\n", first, char(253), second, third);
}

template<class T>
inline void Poly<T>::add(Poly addend)
{
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("We will now add: ");
	print();
	printf("and: ");
	addend.print();
	printf("The sum is: (%d)x%c + (%d)x + (%d)\n",
		first + addend.first,
		char(253),
		second + addend.second,
		third + addend.third);
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++\n");
}

template<class T>
inline void Poly<T>::multiply(Poly multiplier)
{
	printf("**************************************************\n");
	printf("We will now multiply: ");
	print();
	printf("and: ");
	multiplier.print();
	printf("The total is: (%d)x^4 + (%d)x^3 + (%d)x^2 + (%d)x + (%d)\n",
		first * multiplier.first,
		(first * multiplier.second) + (second * multiplier.first),
		(first * multiplier.third) + (second * multiplier.second) + (third * multiplier.first),
		(second * multiplier.third) + (third * multiplier.second),
		third * multiplier.third);
	printf("**************************************************\n");
}