#include <iostream>
#include "VisitorLaTeX.hpp"
#include "visitor.hpp"
#include "iterator.hpp"
#include "base.hpp"
#include <vector>

int main() {

    Base* three = new Op(3);
    Base* seven = new Op(7);
    Base* four = new Op(4);
    Base* two = new Op(2);
    Base* mult = new Mult(seven, four);
    Base* add = new Add(three, mult);
    Base* minus = new Sub(add, two);
    std::vector<Base*> v;
    v.push_back(three);
    v.push_back(seven);
    v.push_back(four);
    v.push_back(two);
    v.push_back(mult);
    v.push_back(add);
    v.push_back(minus);

    VisitorLaTeX LaTex;

    LaTex.PrintLaTeX(v.begin());

	return 0;
}