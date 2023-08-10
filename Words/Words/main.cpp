#include <iostream>
#include <vector>

using namespace std;

vector<string> checkWords (const string str1,const string str2){
    vector <string> array;
    for (int i=0;i<str1.length();i++){
        array.push_back("absent");
    }
    int i = 0, n=0;
    char buf=' ';
    while (i < array.size()){
        if (str2[i]==str1[i]){
            array[i]="correct";
            n++;
            buf=str2[i];
        }
        else{
            for (int j=0;j<array.size();j++){
                if (str2[i]==buf){
                    n--;
                    break;
                }
                if (str2[i]==str1[j] && n<=0){
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
