#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() 
{
    string input;
    cout << "Input (can only be numbers 0-63, and each number to decode, "<<endl;
    cout <<"whether single digit or double digit, must be seperated by a space): ";
    getline(cin, input);

    stringstream ss(input);
    string result;
    int number;

    while (ss >> number) 
    {  
        //Bounds checking
        if (number < 0 || number > 63) 
        {
            cout << "Number " << number << " is out of bounds." << endl;
            return 1;  
        }
        
        
        if (number >= 0 && number <= 25) 
        {
            result += (char) ('A' + number);
        } 
        else if (number >= 26 && number <= 51) 
        {
            result += (char) ('a' + (number - 26));
        } 
        else if (number >= 52 && number <= 61) 
        {
            result += (char) ('0' + (number - 52));  
        } 
        else if (number == 62) 
        {
            result += '+';  
        } 
        else if (number == 63) 
        {
            result += '/';  
        }
    }

    cout << "Converted string: " << result << endl;
    return 0;  
}