#include<iostream>
using std::cout; using std::endl;
#include<vector>
using std::vector;
#include<string>
using std::string;
#include<functional>
using std::multiplies; using std::minus; using std::plus;
#include<numeric>
using std::accumulate;

template <typename T> 
T sum_of_squares(const T& total, const T& element){
    return total + element * element;
} 

int main(){
    long l_result;
    string s_result;
    vector<long> v_l={1,2,3,4,5};
    vector<string> v_s ={"hi", "moms", "everywhere"};

    // basic
    l_result = accumulate(v_l.begin(), v_l.end(), 0l);
    s_result = accumulate(v_s.begin(), v_s.end(), string(""));
    cout << "l_result:"<<l_result<<", s_result:"<<s_result<<endl;

    // change range
    cout << "[1] through [3], start at 100:"
	     << accumulate(v_l.begin()+1, v_l.end()-1, 100) << endl;

    // predefined function objects
    cout << "Sum is:"
	     << accumulate( v_l.begin(),v_l.end(), 1l, plus<long>() )<<endl;  
    cout << "Product is:"
	     << accumulate( v_l.begin(),v_l.end(), 1l, multiplies<long>() )<<endl;
    cout << "Difference is:"
	     << accumulate( v_l.begin(),v_l.end(), 0l, minus<long>() )<<endl;

    // your own function
    cout << "sum of squares is:"
	     << accumulate( v_l.begin(),v_l.end(), 0l, sum_of_squares<long> )<<endl;

    // a lambda
    cout <<"sum of x+2 is:"
	     << accumulate(
            v_l.begin(),
            v_l.end(),
            0,
            [] (const long& total, const long& element){
              return total + element + 2;
            })
	     << endl;
}
