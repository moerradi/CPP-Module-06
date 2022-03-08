#ifndef	__CLASSES_HPP__
#define	__CLASSES_HPP__

#include <iostream>

class Base {
	public:
		virtual ~Base() {}
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

#endif