#include <iostream>
#include "list.h"

using namespace std;

int main()
{
    cout<<"Test line."<<endl;
    
    cout<<"Initializing List..." << endl;
    List<int> myList;
    
    int arbitraryListSize;
    cout << "How big is the list?" << endl;
    cin >> arbitraryListSize;
    
    
    cout << "Setting up list of " << arbitraryListSize << " elements using 'push_back'..." << endl;
    for (int i = 1; i <= arbitraryListSize; i ++)
    {
        myList.push_back(i);
    }
    
    cout << "Current list's elements (should be 1-"<< arbitraryListSize <<"): " << endl;
    myList.printTheList();
    
    cout << "Let's add a zero to the front using push_front" << endl;
    myList.push_front(0);
    cout << "List beginning with 0:" << endl;
    myList.printTheList();
    
    cout << "Removing front item from the list (the 0)" << endl;
    myList.pop_front();
    cout << "Updated list after removal: " << endl;
    myList.printTheList();
    
    cout << "Removing rear item from the list (the " << arbitraryListSize << ")" << endl;
    myList.pop_back();
    cout << "Updated list after removal: " << endl;
    myList.printTheList();
    
    
    cout << "Removing the remaining items, then testing both pop_back and pop_front on empty list..." << endl;
    for (int i = 1; i < arbitraryListSize; i++)
    {
        myList.pop_back();
    }
    myList.pop_back();
    myList.pop_front();
    
    return 0;
}
