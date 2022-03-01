#ifndef __POW_HPP__
#define __POW_HPP__

#include "base.hpp"
#include <math.h>

class Pow : public Base {
public:
    Pow(Base* lhs, Base* rhs) : Base() {
        left = lhs;
        right = rhs;
    }

    virtual double evaluate() {
        return pow(left->evaluate(), right->evaluate());
    }

    virtual std::string stringify() {
        return '(' + left->stringify() + " ** " + right->stringify() + ')';
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

        virtual void accept(Visitor* visitor, int index) {
                if (index == 0) {
                        visitor->visit_pow_begin(this->get_child(index));
                } else if (index == 1) {
                        visitor->visit_pow_middle(this->get_child(index));
                } else {
                        visitor->visit_pow_end(this->get_child(index));
                }
        }

private:
    Base* left;
    Base* right;
};

#endif
