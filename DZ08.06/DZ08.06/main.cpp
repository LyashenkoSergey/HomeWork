#include <iostream>
#include <malloc/malloc.h>

using namespace std;

class Group{
    
};

class Student{
private:
    int id;
    string fio;
    string phone;
    float averageScore;
    int groupRating;
    int streamRating;
public:
    Student(int id, string fio, string phone);
    
    void showInfo(){
        cout<<id<<" "<<fio<<" "<<phone<<" "<<averageScore<<" "<<
        groupRating<<" "<<streamRating<<endl;
    }
    void setId(int id){
        this->id=id;
    }
    void setFio(string fio){
        this->fio=fio;
    }
    void setPhone(string phone){
        this->phone=phone;
    }
    void setAverageScore(int* array){
        size_t size=malloc_size(array)/sizeof(array[0]);
        int sum=0, count=0;
        for (int i=0;i<size;i++){
            sum+=array[i];
            count++;
        }
        averageScore=sum/count;
    }
    int getId(){
        return id;
    }
    string getFio(){
        return fio;
    }
    string getPhone(){
        return phone;
    }
    float getAverageScore(){
        return averageScore;
    }
    int getGroupRating(){
        return groupRating;
    }
    int getStreamRating(){
        return streamRating;
    }
};

void addStudent(Student* group, Student student){
    
}


int main() {
   
    Student* group=NULL;
    
    
    return 0;
}
