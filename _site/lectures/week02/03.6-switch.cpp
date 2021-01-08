#include <iostream>
using std::cout; using std::endl; using std::cin;
#include <iomanip>
using std::noskipws; using std::setw;

/*
  wfp, 7/23/13
  wfp updated 1/19/15
  basic switch
  Purpose:  Count digits in the input stream
*/

int main()
{
    char C;                  // Input character
    long char_count   = 0,    // Number of characters in input stream
	line_count   = 0,    // Number of newlines
	white_count  = 0,    // Number of whitespace characters
	digit_count  = 0,    // Number of digits
	other_count  = 0;    // Number of other characters
    
    cin >> noskipws;
    
    while (cin >> C) {
		++char_count;          // Increment overall character count
		switch (C) {            // Classify each character
			case '\n':           // Newline
				++line_count;
			case ' ':            // White space (newline, blank or tab)
			case '\t':
				++white_count;
				break;
			case '0':            // Decimal digit
			case '1': 
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				++digit_count;
				break;
			default:             // Other character
				++other_count;
				break;
		}
    }  
    
    cout << endl;
    cout << "Newlines:   " << setw( 5 ) << line_count  << endl;
    cout << "Whitespace: " << setw( 5 ) << white_count << endl;
    cout << "Digits:     " << setw( 5 ) << digit_count << endl;
    cout << "Other:      " << setw( 5 ) << other_count << endl;
    cout << "Total:      " << setw( 5 ) << char_count  << endl;
    cout << endl;
}

