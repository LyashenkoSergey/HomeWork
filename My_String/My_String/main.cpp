#include "mystring.h"

int main()
{
    MyString str1 = "askjkjgvckjgd";
    string str2="askjkjgvckjgd";
    
    cout<<str1[0]<<endl;
    cout<<str2[0]<<endl;
    
    (str1<"test")?cout<<"test ok":cout<<"test false";
    (str1>"test")?cout<<"test false":cout<<"test ok";
    (str1<="test")?cout<<"test ok":cout<<"test false";
    (str1>="test")?cout<<"test false":cout<<"test ok";
    str1.show();
    cout<<endl;
    str1.insert('H', 2);
    str1.show();
    cout<<endl;
    cout<<"Size -"<<str1.max_size()<<endl;;
    str1.pop('R');
    str1.show();
    cout<<endl;
    cout<<"Stoi - "<<str1.stoi()<<endl;
    str1.clear();
    str1.show();
    cout<<endl;

}
