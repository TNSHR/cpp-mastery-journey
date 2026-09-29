#pragma once

#include <string>
#include <memory>
#include <utility>

// ============================================================
// Widget — declaration only. Definitions live in ForwardingDemo.cpp
// (same split style as Day 09's ReferenceDemo.h / .cpp)
// ============================================================
class Widget {
public:
    explicit Widget(const std::string& name);
    explicit Widget(std::string&& name);
    Widget(const Widget& other);
    Widget(Widget&& other) noexcept;

    const std::string& name() const { return name_; }

private:
    std::string name_;
};

// ============================================================
// Perfect forwarding factories
// ============================================================
// IMPORTANT DIFFERENCE FROM WIDGET ABOVE:
// These stay fully defined here in the header — they can't be moved
// to ForwardingDemo.cpp the way Widget's methods were. A template
// isn't real code until the compiler instantiates it for a concrete
// type, and that instantiation happens wherever the template is USED
// (main.cpp), not wherever it's written. If the bodies lived in
// ForwardingDemo.cpp instead, main.cpp would compile but fail to
// LINK — the compiler would never generate a Widget-specific version
// of the function. This is a genuinely common "why won't this link"
// bug the first time people try to split templates like normal code.

template <typename T, typename... Args>
std::unique_ptr<T> myMakeUnique(Args&&... args) {
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}

template <typename T, typename... Args>
std::unique_ptr<T> badFactory(Args&&... args) {
    return std::unique_ptr<T>(new T(args...)); // missing std::forward — bug, kept for comparison
}
