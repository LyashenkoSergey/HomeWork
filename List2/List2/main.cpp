#include "list2.h"




int main(int argc, const char * argv[]) {
    List<int> myList;
    myList.push(234);
    myList.show();
    cout<<endl;
    myList.push_front(2342);
    myList.show();
    cout<<endl;
    myList.push_back(3234);
    myList.show();
    cout<<endl;
    
    myList.insert(23, 1);
    myList.show();
    cout<<endl;
    
    myList.pop_back();
    myList.show();
    cout<<endl;
    
    myList.pop_front();
    myList.show();
    cout<<endl;
    
    
    return 0;
}
