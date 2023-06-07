#include "param.h"

class Student {
private:
    string name;
    int* grades=nullptr;
    static int countGrades;
    int gradesAtQuater[4];
    static int countGradesAtQuater;
    int gradeAtYear=0;
public:
    Student();
    Student(string name) {
        this->name = name;
    }
    bool operator ==(Student& student){
        if (this->name==student.name)
            return true;
        else
            return false;
    }
    void addGrades(int grade){
        if (grades==nullptr){
            int* buf=new int[1]{};
            buf[0]=grade;
            countGrades++;
        }
        else{
            int* buf=new int[countGrades+1];
            for (int i=0; i<countGrades;i++){
                buf[i]=grades[i];
            }
            buf[countGrades]=grade;
            delete[] grades;
            grades=buf;
            countGrades++;
        }
    }
    
    void setGradeAtQuater(int*& grades){
        int sum=0;
        for (int i=0; i<countGrades; i++){
            sum+=grades[i];
        }
        gradesAtQuater[countGradesAtQuater]=sum/countGrades;
        countGradesAtQuater++;
        delete[] grades;
        grades=nullptr;
        countGrades=0;
    }
    
    void setGradeAtYear(int*& gradesAtQuater){
        gradeAtYear=0;
        int sum=0;
        for (int i=0;i<4;i++){
            sum+=gradesAtQuater[i];
        }
        gradeAtYear=sum/4;
        gradesAtQuater=nullptr;
        countGradesAtQuater=0;
        countGrades=0;
        grades=nullptr;
    }
    
    void setStudentName(string name){
        this->name=name;
    }
    
    int* getGrates(){
        return grades;
    }
    int* getGratesAtQuater(){
        return gradesAtQuater;
    }
    
    void showInfo() {
        cout << name << endl;
        if (countGrades!=0){
            cout<<"All grades at quater "<<countGradesAtQuater<<" - ";
            for (int i=0; i<countGrades;i++){
                cout<<grades[i]<<"; ";
            }
            cout<<endl;
        }
        if (countGradesAtQuater!=0){
            cout<<endl<<"The grades for quater - ";
            for (int i=0;i<countGradesAtQuater;i++){
                cout<<"At "<<i<<" quater - "<<gradesAtQuater[i]<<"; ";
            }
            cout<<endl;
        }
        if (gradeAtYear!=0){
            cout<<"The grades for year - "<<gradeAtYear<<endl;
        }
        cout<<endl;
    }
};
int Student::countGrades=0;
int Student::countGradesAtQuater=0;

class Journal {
private:
    string name;
    Student* students=nullptr;
public:
    Journal(string name){
        this->name=name;
    }
    void setStudents(Student*& students){
        this->students=new Student[COUTNSTUDENTS];
        for (int i=0;i<COUTNSTUDENTS;i++){
            this->students[i]=students[i];
        }
    }
    bool searchStudent(Student student){
        bool flag=false;
        for (int i=0;i<COUTNSTUDENTS;i++){
            if (this->students[i]==student){
                flag=true;
                break;
            }
        }
        return flag;
    }
    void addGradeAtStudent(Student& student,int grade){
        if (searchStudent(student)){
            student.addGrades(grade);
        }
        else cout<<"Student is not found";
    }
    void addGradeStudentAtQuater(Student& student){
        student.setGradeAtQuater(student.getGrates());
    }
    void addGrateStudentAtYear(Student& student){
        student.setGradeAtYear(student.getGratesAtQuater());
    }
    void showInfo(){
        for (int i=0;i<COUTNSTUDENTS;i++){
            students[i].showInfo();
        }
    }
   
};

string* readFromFile(string path){
    ifstream in(path);
    string* buf=new string[]{"The file is not found"};
    if (in.is_open()){
        string str;
        int counter=0;
        while (getline(in,str)){
            counter++;
        }
        in.close();
        in.open(path);
        buf=new string[counter]{};
        counter=0;
        while (getline(in,str)){
            buf[counter++]=str;
        }
        in.close();
    }
        return buf;
}
void writeInFile(string* array, int size, string path) {
    ofstream out;
    out.open(path);
    string str="";
    for (int i=0; i<size;i++){
        out << str << endl;
    }
    out.close();
}



string generateFI(string* last, string* first) {
    string buf;
        buf = last[rand()] + first[rand()];
return buf;
}

void showArray(string* array) {
    for (int i = 0; i < COUTNSTUDENTS; i++) {
        cout<<array[i]<<endl;
    }
}

int main() {
    Student* students = new Student[COUTNSTUDENTS];
    for (int i=0;i<COUTNSTUDENTS;i++){
        students[i].setStudentName(generateFI(LASTNAME, FIRSTNAME));
    }
    Journal journal("5A");
    journal.setStudents(students);
    
    journal.showInfo();
        
        
    
    
    
}
