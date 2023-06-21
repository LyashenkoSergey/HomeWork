#include "list2.h"




int main(int argc, const char * argv[]) {
    List<int> myList;
    myList.push(234);
    myList.push_front(2342);
    myList.push_back(3234);
    myList.show();
    
    myList.insert(23, 1);
    myList.show();
    
    myList.pop_back();
    myList.show();
    
    myList.pop_front();
    myList.show();
    
    
    return 0;
}
