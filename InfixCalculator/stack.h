#ifndef STACK_H
#define STACK_H

#include <cstdlib>
#include <stdexcept>
#include "vector.h"
#include <new>


namespace my {
    template<class T, class Container = Vector<T>>
    class Stack {
        Container c;

    public:
        using value_type = T;

        //constructor: takes an optional arguments
        template<class... Args>
        explicit Stack(Args&&... args): c(std::forward<Args>(args)...) {}

        Stack(const Stack& other) = default;

        Stack(Stack&& other) noexcept = default;

        Stack& operator=(const Stack& other) = default;

        Stack& operator=(Stack&& other)  noexcept = default;

        //resets the state of the stack to it's default state
        void reset() { c.reset(); }

        template<class... Args>
        void push(Args&&... args) { c.push_back(std::forward<Args>(args)...); }

        T& top() { return c.back(); }

        const T& top() const { return c.back(); }

        void pop() { c.pop_back(); }

        T popAndGet() {
            T retval = c.back();
            c.pop_back();
            return retval;
        }

        [[nodiscard]] constexpr bool isEmpty() const { return c.isEmpty(); }
    };
}

#endif //STACK_H
