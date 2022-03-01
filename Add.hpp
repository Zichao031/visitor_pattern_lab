#ifndef __ADD_HPP__
#define __ADD_HPP__

#include "base.hpp"

class Add : public Base {
public:
    Add(Base* lhs, Base* rhs) : Base() {
        left = lhs;
        right = rhs;
    }

    virtual double evaluate() {
        return left->evaluate() + right->evaluate();
    }

    virtual std::string stringify() {
        return '(' + left->stringify() + " + " + right->stringify() + ')';
    }

    virtual int number_of_children() { 
	if (left && right) {
	    return 2;
	} else { return 1;}
    }
    virtual Base* get_child(int i) {
	if (i = 0) {
	    return left;
	} else if (i = 1) {
	    return this;
	} else {
	    return right;
	}
    }
private:
    Base* left;
    Base* right;
};

#endif
