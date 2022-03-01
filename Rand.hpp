#ifndef __RAND_HPP__
#define __RAND_HPP__

#include "base.hpp"
#include <string>

class Rand : public Base {
private:
    	double val;
public:
    	Rand() : Base() {
        	val = rand() % 100;
    	}
    	virtual double evaluate() { return val; }
    	virtual std::string stringify() { return std::to_string(val); }
	virtual int number_of_children() { return 0; }
        virtual Base*  get_child(int i) { return nullptr }

};

#endif //__RAND_HPP__
