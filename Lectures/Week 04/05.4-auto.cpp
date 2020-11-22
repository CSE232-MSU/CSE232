#include<iostream>
using std::cout; using std::endl; using std::cin;


int main() {
    // using, better than old typdef
    using clc_ptr = const long* const;
    long my_long = 123;
    clc_ptr ptr = &my_long;

    // auto, when it's clear
    long the_sum = 0;
    for (auto i = 0; i < my_long; ++i) {
	    the_sum += i*2;
    }

    auto p_long = &my_long;
    cout << "my_long:" << &my_long << ", " << my_long << endl;    
    cout << "p_long:"  << &p_long  << ", " << p_long << ", " << *p_long << endl;

    // auto drops references and const;
    long &my_ref = my_long;
    // auto_long is of type long
    auto auto_long = my_ref;
    my_long = 456;
    cout << my_ref << "," << my_long << "," << auto_long << endl;

    const long my_const = my_long;
    // another_long is of type long
    auto another_long = my_const;
    another_long = 789;
}
