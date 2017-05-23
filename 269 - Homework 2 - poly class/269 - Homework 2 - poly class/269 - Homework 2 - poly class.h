#pragma once

int main();
//Poly.h

#ifdef  __POLY_H__
#define __POLY_H__

#include "stdio.h"

template <class T>
class Poly
{
public:
	T first, second, third;
	Poly(T a, T b, T c);
	void print();
	//void add(Poly addend);
	//void multiply(Poly multiplier);
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
	printf("(%d)x² + (%d)x + (%d)\n", first, second, third);
}