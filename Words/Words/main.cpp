#include <iostream>
#include <vector>

using namespace std;

vector<string> checkWords (const string str1,const string str2){
    vector <string> array;
    for (int i=0;i<str1.length();i++){
        array.push_back("absent");
    }
    int i = 0;
    while (i < array.size()){
        if (str1[i]==str2[i]){
            array[i]="correct";
        }
        else{
            for (int j=0;j<array.size();j++){
                if (str1[i]==str2[j]){
                    array[i]="present";
                }
            }
        }
        i++;
    }

    return array;
}

void showArray(const vector<string> array){
    for (int i=0;i<array.size();i++){
        cout<<array[i]<<endl;
    }
}

int main() {
    string str1,str2;
    do {
        cout<<"Enter the first word - ";
        cin>>str1;
        cout<<endl;
        cout<<"Enter the second word - ";
        cin>>str2;
        cout<<endl;
    }
    while(str1.length()!=str2.length());
    vector<string> array=checkWords(str1, str2);
    showArray(array);
    
    
    
    return 0;
}
