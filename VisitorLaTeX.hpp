#ifndef __VISITORLATEX_HPP__
#define __VISITORLATEX_HPP__

#include "visitor.hpp"
#include "Base.hpp"
#include "iterator.hpp"
#include <iostream>
using namespace std;


class VisitorLaTeX : public Visitor {
public:
//    std::string PrintLaTeX(Base* ptr) {
//        for (Iterator i = Iterator(ptr); i.is_done(); i.next()) {
//            i.current_node()->accept(this, i.current_index());
//        }
//    }
    std::string PrintLaTeX(Base* ptr) {
        for (Iterator i = Iterator(ptr); i.is_done(); i.next()) {
            i.current_node()->accept(this, i.current_index());
        }
    }

    virtual ~VisitorLaTeX() = default;

    // Nodes with no children are visited only once (index = 0)
    virtual void visit_op(Op* node) {
        cout << "{";
        node->stringify();
        cout << "}";
    }
    virtual void visit_rand(Rand* node) {
        cout << "{";
        node->stringify();
        cout << "}";
    }

    // Nodes with two children are visited three times.
    // index = 0 -> begin
    // index = 1 -> middle
    // index = 2 -> end
    virtual void visit_add_begin(Add* node) {
        cout << "{(";
        node->get_child(0)->stringify();
    }
    virtual void visit_add_middle(Add* node) {
        cout << " + ";
    }
    virtual void visit_add_end(Add* node) {
        node->get_child(2)->stringify();
        cout << ")}";
    }
    virtual void visit_sub_begin(Sub* node) {
        cout << "{(";
        node->get_child(0)->stringify();
    }
    virtual void visit_sub_middle(Sub* node) {
        cout << " - ";
    }
    virtual void visit_sub_end(Sub* node) {
        node->get_child(2)->stringify();
        cout << ")}";
    }
    virtual void visit_mult_begin(Mult* node) {
        cout << "{(";
        node->get_child(0)->stringify();
    }
    virtual void visit_mult_middle(Mult* node) {
        cout << " \cdot ";
    }
    virtual void visit_mult_end(Mult* node) {
        node->get_child(2)->stringify();
        cout << ")}";
    }
    virtual void visit_div_begin(Div* node) {
        cout << "{\\frac";
        node->get_child(0)->stringify();
    }
    virtual void visit_div_middle(Div* node) {
        cout << " ";
    }
    virtual void visit_div_end(Div* node) {
        node->get_child(2)->stringify();
        cout << "}";
    }
    virtual void visit_pow_begin(Pow* node) {
        cout << "{(";
        node->get_child(0)->stringify();
    }
    virtual void visit_pow_middle(Pow* node) {
        cout << " ^ ";
    }
    virtual void visit_pow_end(Pow* node) {
        node->get_child(2)->stringify();
        cout << ")}";
    }
};
#endif // __VISITORLATEX_HPP__