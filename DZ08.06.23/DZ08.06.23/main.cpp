#include <iostream>
#include <ctime>
using namespace std;

int uniqId = 0;
/*
1. Группа должна
содержать массив студентов
id
фио
номер-телефона
ср.балл
рейтинг в группе
рейтинг в потоке

возможность добавления студента в группу
удаление из группы по id
вывод всех студентов
поиск студента по id


Добавить класс, содержащий название дисциплины и массив оценок

Добавить метод добавления студенту необходимой дисциплины
а также добавление оценок в указанную дисциплину конкретному студенту

*/

class Subject {
    string name;
    int* marks = nullptr;
    int counter = 0;
public:
    Subject() {}
    Subject(string name) {
        this->name = name;
    }
    string getName(){
        return name;
    }
    void addMark(int mark) {
        int* buf = new int[counter + 1];
        for (int i = 0; i < counter; i++) {
            buf[i] = marks[i];
        }
        buf[counter++] = mark;
        delete[]marks;
        marks = buf;
    }
    void showInfo() {
        cout << name << " : [";
        for (int i = 0; i < counter; i++) {
            cout << marks[i] << ", ";
        }
        cout << "\b]" << endl;
    }


};


class Student {
    static int countId;
    int id;
    string fio;
    string phone;
    float mark = 0;
    int raitingInGroup = 0;
    int raitingInStream = 0;
    Subject* subjects = nullptr;
    int counterSubjects = 0;
public:
    Student() {}
    Student(string fio, string phone) {
        this->id =countId++;
        this->fio = fio;
        this->phone = phone;
    }
    void setPhone(string phone) {
        this->phone = phone;
    }
    void setMark(float mark) {
        this->mark = mark;
    }
    void setRaitingInGroup(int raitingInGroup) {
        this->raitingInGroup = raitingInGroup;
    }
    void setRaitingInStream(int raitingInStream) {
        this->raitingInStream = raitingInStream;
    }
    static int getCountId() {
        return countId;
    }
    int getId() {
        return id;
    }
    string getFio() {
        return fio;
    }
    string getPhone() {
        return phone;
    }
    float getMark() {
        return mark;
    }
    int getRaitingInGroup() {
        return raitingInGroup;
    }
    int getRaitingInStream() {
        return raitingInStream;
    }
    void showInfo() {
        cout << id << " " << fio << " " << phone << " " << mark << " " << raitingInGroup << " " << raitingInStream << endl;
        for (int i = 0; i < counterSubjects; i++) {
            subjects[i].showInfo();
        }
    }
    void addSubject(string nameSubject) {
        Subject newSubject(nameSubject);
        Subject* buf = new Subject[counterSubjects + 1];
        for (int i = 0; i < counterSubjects; i++) {
            buf[i] = subjects[i];
        }
        buf[counterSubjects++] = newSubject;
        delete[]subjects;
        subjects = buf;
    }
    void addMark(string nameSubject, int mark) {
        int n=0;
        for (int i=0; i<counterSubjects;i++){
            if (subjects[i].getName()==nameSubject){
                n=i;
                break;
            }
        }
        subjects[n].addMark(mark);
    }

};
int Student::countId = 0;

class Group {
    string numGroup;
    Student* students = nullptr;
    int counter = 0;
public:
    Group(string numGroup) {
        this->numGroup = numGroup;
    }
    void showAllStudents() {
        for (int i = 0; i < counter; i++) {
            students[i].showInfo();
        }
    }
    Student* searchStudent(int id) {
        for (int i = 0; i < counter; i++) {
            if (id == students[i].getId()) return &students[i];
        }
        return nullptr;
    }
    void addStudent(Student& st) {
        Student* buf = new Student[counter + 1];
        for (int i = 0; i < counter; i++) {
            buf[i] = students[i];
        }
        buf[counter++] = st;
        delete[]students;
        students = buf;
    }
    void removeStudent(int id) {
        Student* searchSt = searchStudent(id);
        if (searchSt != nullptr) {
            if (counter == 1) {
                delete[]students;
                students = nullptr;
            }
            else {
                int n = 0;
                for (int i = 0; i < counter; i++) {
                    if (searchSt == &students[i]) n = i;
                }
                Student* buf = new Student[counter - 1];
                for (int i = 0; i < n; i++) {
                    buf[i] = students[i];
                }
                for (int i = n + 1; i < counter; i++) {
                    buf[i - 1] = students[i];
                }
                delete[]students;
                students = buf;
            }
            counter--;
        }
    }






};





int main()
{
    srand(time(NULL));
    Student st1("Vasia", "123");
    Student st2("Vasia2", "1234");
    Student st3("Vasia3", "12345");
    Student st4("Vasia4", "123456");
    
    Group gr1("5A");
    cout << "start group" << endl;
    gr1.showAllStudents();
    cout << "after add students" << endl;
    gr1.addStudent(st1);
    gr1.addStudent(st2);
    gr1.addStudent(st3);
    gr1.addStudent(st4);
    gr1.showAllStudents();
    cout << "after remove students" << endl;
    gr1.removeStudent(2);
    gr1.showAllStudents();
    cout << "after add mathematic" << endl;
    st1.addSubject("mathematic");
    st1.addMark("mathematic", 5);
    
    gr1.showAllStudents();
}

    
