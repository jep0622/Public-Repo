#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string b64encode(const string &input) 
{
    stringstream result;

    for (char ch : input) 
    {
        if (ch >= 'A' && ch <= 'Z') 
        {
            result << (ch - 'A');
        } 
        else if (ch >= 'a' && ch <= 'z') 
        {
            result << (ch - 'a' + 26);
        } 
        else if (ch >= '0' && ch <= '9') 
        {
            result << (ch - '0' + 52);
        } 
        else if (ch == '+')
        {
            result << "62";
        } 
        else if (ch == '/') 
        {
            result << "63";
        } 
        else 
        {
            //Just to ignore any character outside of the bounds of this encryption
            continue;
        }
        
        result << " ";
    }

    return result.str();
}

int main() {
    string input;

    cout << "Input: ";
    getline(cin, input);

    string encodedString = b64encode(input);
    cout << "Encoded output: " << encodedString << endl;

    return 0;
}