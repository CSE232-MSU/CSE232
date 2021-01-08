#include<iostream>
using std::cout; using std::endl; using std::cin;


double my_fn(long num){
    double pi = 3.1415926535;
    double pi_div = pi/static_cast<double>(num);
    cout << "pi over "<<num<<" is "<<pi_div<<endl;
    num = num * (pi * 2);
    cout << "Num is:"<<num<<endl;
    return pi_div;
}

int main (){
    long num;
    double result;
    cout << "What number:";
    cin >> num;
    result = my_fn(num);
    cout << "Num is:"<<num<<endl;
    // cout << pi; // can't, not defined in this scope
    // cout << pi_div; //ditto;
    cout << "Result is:"<<result << endl;
}
