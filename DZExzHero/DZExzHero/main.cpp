#include "param.h"

template<typename T>
T** createArray(int size1, int size2){
    T** buf=new T*[size1];
    for (int i=0;i<size1;i++){
        buf[i]=new T[size2];
    }
    return buf;
}

template<typename T>
T* createArray(int size){
    T* buf=new T[size];
    
    return buf;
}

template<typename T>
void fillingArray(T**& array, T a, T b){
    if (a>b) swap(a,b);
    int size1=malloc_size(array)/sizeof(array[0]);
    int size2=malloc_size(array[0])/sizeof(array[0][0]);
    for (int i=0;i<size1;i++){
        for (int j=0;j<size2;j++){
            array[i][j]=a+rand()%(b+1-a);
        }
    }
}

template<typename T>
void fillingArray(T*& array, T a, T b){
    if (a>b) swap(a,b);
    int size1=malloc_size(array)/sizeof(array[0]);
    for (int i=0;i<size1;i++){
         array[i]=a+rand()%(b+1-a);
        }
    }

template<typename T>
void showArray(T** array){
    int size1=malloc_size(array)/sizeof(array[0]);
    int size2=malloc_size(array[0])/sizeof(array[0][0]);
    for (int i=0;i<size1;i++){
        for (int j=0;j<size2;j++){
            cout<<array[i][j]<<" ";
        }
        cout<<endl;
    }
}

template<typename T>
void showArray(T* array){
    int size1=malloc_size(array)/sizeof(array[0]);
    for (int i=0;i<size1;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
}

template<typename T>
void sortArray(T**& array){
    int size1=malloc_size(array)/sizeof(array[0]);
    int size2=malloc_size(array[0])/sizeof(array[0][0]);
    for (int i=size1;i>0;i--){
        for (int j=size2;j>1;j--){
            for (int k=size1-1;k>0;k--){
                for (int l=size2-1;l>0;l--){
                    if (array[i][j]<array[k][l])
                        swap(array[i][j],array[k][l]);
                }
            }
                
        }
    }
}

template<typename T>
void sortArray(T*& array){
    int size=malloc_size(array)/sizeof(array[0]);
    for (int i=size;i>0;i--){
        for (int j=size-1;j>0;j--){
             if (array[i]<array[j])
                 swap(array[i],array[j]);
        }
    }
}

template<typename T>
T** deleteIndexInArray (T** array, int index){
    int size1=malloc_size(array)/sizeof(array[0]);
    int size2=malloc_size(array[0])/sizeof(array[0][0]);
    T** buf=new T*[size1-1];
    for (int i=0;i<size1-1;i++){
        buf[i]=new T[size2];
    }
    for (int i=0; i<index;i++){
        buf[i]=array[i];
    }
    for (int i=index+1;i<size1;i++){
        buf[i-1]=array[i];
    }
    delete[] array;
    array=buf;
    return array;
    
}

template<typename T>
T* deleteIndexInArray (T* array, int index){
    int size1=malloc_size(array)/sizeof(array[0]);
    T* buf=new T[size1-1];
    for (int i=0; i<index;i++){
        buf[i]=array[i];
    }
    for (int i=index+1;i<size1;i++){
        buf[i-1]=array[i];
    }
    delete[] array;
    array=buf;
    return array;
    
}

template<typename T>
int findSymbolInArray(T** array, T symbol){
    int size1=malloc_size(array)/sizeof(array[0]);
    int size2=malloc_size(array[0])/sizeof(array[0][0]);
    for (int i=size1;i>0;i--){
        for (int j=size2;j>0;j--){
            if (array[i][j]==symbol){
                return i;
                break;
            }
        }
    }
    return -1;
}

template<typename T>
int findSymbolInArray(T* array, T symbol){
    int size1=malloc_size(array)/sizeof(array[0]);
    for (int i=size1;i>0;i--){
            if (array[i]==symbol){
                return i;
                break;
            
        }
    }
    return -1;
}

template<typename T>
T* readFile(string path){
    ifstream in(path);
    if (in.is_open()){
        string str;
        int count=0;
        while (getline(in,str)) {
            count++;
        }
        T* buf=new T[count];
        in.close();
        in.open(path);
        count=0;
        while (getline(in,str)) {
            buf[count++]=str;
        }
        in.close();
        return buf;
    }
    else cout<<"the path is incorrect"<<endl;
}

template<typename T>
T* writeFile(string path, T* array){
    ofstream out(path, ios::app);
    int size=malloc_size(array)/sizeof(array[0]);
    for (int i=0;i<size;i++){
        out<<array[i];
    }
    out.close();
}

template<typename T>
int countSymbolsInFile(string path){
    ifstream in(path);
    if (in.is_open()){
        string str;
        int count=0;
        while (getline(in,str)) {
            count++;
        }
        T* buf=new T[count];
        in.close();
        in.open(path);
        count=0;
        while (getline(in,str)) {
            buf[count++]=str;
        }
        in.close();
        int size=malloc_size(buf)/sizeof(buf[0]);
        return size;
    }
    else cout<<"the path is incorrect"<<endl;
}

template<typename T>
int countRowsInFile(string path){
    ifstream in(path);
    if (in.is_open()){
        string str;
        int count=0;
        while (getline(in,str)) {
            count++;
        }
        return count;
      
    }
    else cout<<"the path is incorrect"<<endl;
}



int main() {
    setlocale(LC_ALL, "rus");
    
    
    
    
}
