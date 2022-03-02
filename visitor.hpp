#ifndef __VISITOR_HPP__
#define __VISITOR_HPP__

#include "base.hpp"
#include <string>

class Op : public Base {
private:
    double val = 0;
public:
    Op(double value) : Base() {
        val = value;
    }
    virtual double evaluate() { return val; }
    virtual std::string stringify() { return std::to_string(val); }
    virtual int number_of_children() { return 0; }
    virtual Base* get_child(int i) { return nullptr; }
    virtual void accept(Visitor* visitor, int index) {
        visitor->visit_op(this);
    }
};

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
    virtual Base* get_child(int i) { return nullptr; }
    virtual void accept(Visitor* visitor, int index) {
        visitor->visit_rand(this);
    }
};

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
        return this->stringify();
    }

    virtual int number_of_children() {
        if (left && right) {
            return 2;
        }
        else { return 1; }
    }
    virtual Base* get_child(int i) {
        if (i = 0) {
            return left;
        }
        else if (i = 1) {
            return this;
        }
        else {
            return right;
        }
    }
    virtual void accept(Visitor* visitor, int index) {
        if (index == 0) {
            visitor->visit_add_begin(this);
        }
        else if (index == 1) {
            visitor->visit_add_middle(this);
        }
        else {
            visitor->visit_add_end(this);
        }
    }

private:
    Base* left;
    Base* right;
};

class Sub : public Base {
public:
    Sub(Base* lhs, Base* rhs) : Base() {
        left = lhs;
        right = rhs;
    }

    virtual double evaluate() {
        return left->evaluate() - right->evaluate();
    }

    virtual std::string stringify() {
        return this->stringify();
    }
    virtual int number_of_children() {
        if (left && right) {
            return 2;
        }
        else { return 1; }
    }
    virtual Base* get_child(int i) {
        if (i = 0) {
            return left;
        }
        else if (i = 1) {
            return this;
        }
        else {
            return right;
        }
    }

    virtual void accept(Visitor* visitor, int index) {
        if (index == 0) {
            visitor->visit_sub_begin(this);
        }
        else if (index == 1) {
            visitor->visit_sub_middle(this);
        }
        else {
            visitor->visit_sub_end(this);
        }
    }

private:
    Base* left;
    Base* right;
};

class Mult : public Base {
public:
    Mult(Base* lhs, Base* rhs) : Base() {
        left = lhs;
        right = rhs;
    }

    virtual double evaluate() {
        return left->evaluate() * right->evaluate();
    }

    virtual std::string stringify() {
        return this->stringify();
    }
    virtual int number_of_children() {
        if (left && right) {
            return 2;
        }
        else { return 1; }
    }
    virtual Base* get_child(int i) {
        if (i = 0) {
            return left;
        }
        else if (i = 1) {
            return this;
        }
        else {
            return right;
        }
    }

    virtual void accept(Visitor* visitor, int index) {
        if (index == 0) {
            visitor->visit_mult_begin(this);
        }
        else if (index == 1) {
            visitor->visit_mult_middle(this);
        }
        else {
            visitor->visit_mult_end(this);
        }
    }

private:
    Base* left;
    Base* right;
};

class Div : public Base {
public:
    Div(Base* lhs, Base* rhs) : Base() {
        left = lhs;
        right = rhs;
    }

    virtual double evaluate() {
        if (right->evaluate() == 0.0) {
            return std::numeric_limits<double>::max();
        }
        return left->evaluate() / right->evaluate();
    }

    virtual std::string stringify() {
        return this->stringify();
    }
    virtual int number_of_children() {
        if (left && right) {
            return 2;
        }
        else { return 1; }
    }
    virtual Base* get_child(int i) {
        if (i = 0) {
            return left;
        }
        else if (i = 1) {
            return this;
        }
        else {
            return right;
        }
    }

    virtual void accept(Visitor* visitor, int index) {
        if (index == 0) {
            visitor->visit_div_begin(this);
        }
        else if (index == 1) {
            visitor->visit_div_middle(this);
        }
        else {
            visitor->visit_div_end(this);
        }
    }

private:
    Base* left;
    Base* right;
};

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
        return this->stringify();
    }
    virtual int number_of_children() {
        if (left && right) {
            return 2;
        }
        else { return 1; }
    }
    virtual Base* get_child(int i) {
        if (i = 0) {
            return left;
        }
        else if (i = 1) {
            return this;
        }
        else {
            return right;
        }
    }

    virtual void accept(Visitor* visitor, int index) {
        if (index == 0) {
            visitor->visit_pow_begin(this);
        }
        else if (index == 1) {
            visitor->visit_pow_middle(this);
        }
        else {
            visitor->visit_pow_end(this);
        }
    }

private:
    Base* left;
    Base* right;
};

class Visitor{
    public:
        virtual ~Visitor() = default;

        // Nodes with no children are visited only once (index = 0)
        virtual void visit_op(Op* node) = 0;
        virtual void visit_rand(Rand* node) = 0;

        // Nodes with two children are visited three times.
        // index = 0 -> begin
        // index = 1 -> middle
        // index = 2 -> end
        virtual void visit_add_begin(Add* node) = 0;
        virtual void visit_add_middle(Add* node) = 0;
        virtual void visit_add_end(Add* node) = 0;
        virtual void visit_sub_begin(Sub* node) = 0;
        virtual void visit_sub_middle(Sub* node) = 0;
        virtual void visit_sub_end(Sub* node) = 0;
        virtual void visit_mult_begin(Mult* node) = 0;
        virtual void visit_mult_middle(Mult* node) = 0;
        virtual void visit_mult_end(Mult* node) = 0;
        virtual void visit_div_begin(Div* node) = 0;
        virtual void visit_div_middle(Div* node) = 0;
        virtual void visit_div_end(Div* node) = 0;
        virtual void visit_pow_begin(Pow* node) = 0;
        virtual void visit_pow_middle(Pow* node) = 0;
        virtual void visit_pow_end(Pow* node) = 0;
};

#endif //__VISITOR_HPP__
