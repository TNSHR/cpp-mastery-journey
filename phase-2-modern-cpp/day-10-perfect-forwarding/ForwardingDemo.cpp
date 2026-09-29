#include "ForwardingDemo.h"
#include <iostream>

Widget::Widget(const std::string& name) : name_(name) {
    std::cout << "  [Widget]  COPY-constructed from lvalue: \"" << name_ << "\"\n";
}

Widget::Widget(std::string&& name) : name_(std::move(name)) {
    std::cout << "  [Widget]  MOVE-constructed from rvalue: \"" << name_ << "\"\n";
}

Widget::Widget(const Widget& other) : name_(other.name_) {
    std::cout << "  [Widget]  COPY constructor: \"" << name_ << "\"\n";
}

Widget::Widget(Widget&& other) noexcept : name_(std::move(other.name_)) {
    std::cout << "  [Widget]  MOVE constructor: \"" << name_ << "\"\n";
}
