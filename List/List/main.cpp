#include <iostream>
#include "list.h"

using namespace std;


int main()
{
    
    List<int> list;
    list.push(2);
    list.push(5);
    list.push(6);
    list.show();
    cout << endl;
    list.insert(9, 2);
    list.show();
    cout << endl;
}
