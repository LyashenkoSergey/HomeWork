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
    string getName(){
        return name;
    }
    int getCountGrades(){
        return countGrades;
    }
    int* getGrates(){
        return grades;
    }
    int* getGratesAtQuater(){
        return gradesAtQuater;
    }
    int getCountGradesAtQuater(){
        return countGradesAtQuater;
    }
    int getGradeAtYear(){
        return gradeAtYear;
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
    ~Student(){
        delete[] grades;
    }
};
int Student::countGrades=0;
int Student::countGradesAtQuater=0;

class Journal {
private:
    string name;
    Student* students=nullptr;
public:
    Journal();
    Journal(string name){
        this->name=name;
    }
    void operator =(Journal& journal){
        this->name=journal.name;
        Student* students=new Student[COUTNSTUDENTS];
        this->students=journal.students;
    }
    void setStudents(Student*& students){
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
    bool searchStudent(string name){
        bool flag=false;
        for (int i=0;i<COUTNSTUDENTS;i++){
            if (this->students[i].getName()[0]==name[0]){
                flag=true;
                for (int j=1; j<sizeof(students[i].getName());j++){
                    if (students[i].getName()[j]!=name[j]){
                        flag=false;
                        break;
                    }
                }
            }
        }
        return flag;
    }
    Student searchStudentReturnStudent(string name){
        int number=-1;
        for (int i=0;i<COUTNSTUDENTS;i++){
            if (this->students[i].getName()[0]==name[0]){
                number=i;
                for (int j=1; j<sizeof(students[i].getName());j++){
                    if (students[i].getName()[j]!=name[j]){
                        number=-1;
                        break;
                    }
                }
            }
        }
        return students[number];
    }
    void addGradeAtStudent(Student& student,int grade){
        if (searchStudent(student)){
            student.addGrades(grade);
        }
        else cout<<"Student is not found";
    }
    void addGradeStudentAtQuater(Student& student){
        int* buf=new int[students->getCountGrades()];
        student.setGradeAtQuater(buf);
    }
    void addGrateStudentAtYear(Student& student){
        int* buf=new int[students->getCountGradesAtQuater()];
        student.setGradeAtYear(buf);
    }
    Student* getStudents(){
        return students;
    }
    void showInfo(){
        for (int i=0;i<COUTNSTUDENTS;i++){
            students[i].showInfo();
        }
    }
    string getJournalName(){
        return name;
    }
    ~Journal(){
        delete[] students;
    }
};

Journal* readFromFile(string path){
    ifstream in(path);
    Journal* journal=new Journal[1];
    string* buf=nullptr;
    string str="";
    int counter=0;
    if (in.is_open()){
        while (getline(in,str)) {
            counter++;
        }
        buf=new string[counter];
        counter=0;
        in.close();
        in.open(path);
        while (getline(in,str)) {
            buf[counter++]=str;
        }
        
    }
    return journal;
}

void writeInFile(Journal journal, string path) {
    ofstream out;
    out.open(path);
    string str="";
    out<<journal.getJournalName()<<endl;
    for (int i=0; i<COUTNSTUDENTS;i++){
        out << i<< "\t:"<<journal.getStudents()[i].getName()<<"\t:";
        for (int j=0;j<journal.getStudents()[i].getCountGrades();j++){
            out<<journal.getStudents()[i].getGrates()[j];
        }
        out<<":";
        for (int j=0;j<4;j++){
            out<<journal.getStudents()[i].getGratesAtQuater()[j];
        }
        out<<":";
        out<<journal.getStudents()[i].getGradeAtYear();
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
    Student* students;
    Journal journal;
    
    int num;
    do {
        cout<<"Чтобы задать название класса нажмите \t\"1\""<<endl;
        cout<<"Чтобы сгенерировать студентов в классе нажмите \t\"2\""<<endl;
        cout<<"Чтобы добавить оценку студенту нажмите \t\"3\""<<endl;
        cout<<"Чтобы выставить четвертные оценки студентам нажмите \t\"4\""<<endl;
        cout<<"Чтобы выставить годовые оценки студентам нажмите \t\"5\""<<endl;
        cout<<"Чтобы посмотреть информацию по студенту нажмите \t\"6\""<<endl;
        cout<<"Чтобы посмотреть информацию по всем классу нажмите \t\"7\""<<endl;
        cout<<"Чтобы сохранить все данные нажмите \t\"8\""<<endl;
        cout<<"Чтобы считать данные нажмите \t\"9\""<<endl;
        cout<<"Чтобы выйти из программы введите\t\"100\""<<endl;
        cin>>num;
        switch (num){
            case 1: {
                string name="";
                cout<<"Введите название класса"<<endl;
                cin>>name;
                Journal journal(name);
                break;
            }
            case 2:{
                students=new Student[COUTNSTUDENTS];
                for (int i=0;i<COUTNSTUDENTS;i++){
                    students[i].setStudentName(generateFI(LASTNAME, FIRSTNAME));
                }
                journal.setStudents(students);
                break;
            }
            case 3:{
                string name="";
                int grade;
                do{
                    cout<<"Введите фамилию и имя студента"<<endl;
                    cin>>name;
                    if (!journal.searchStudent(name)){
                        cout<<"Студента с таким именем не найдено, попробуйте снова"<<endl;
                    }
                        } while (journal.searchStudent(name));
                cout<<"Введите оценку - ";
                cin>>grade;
                if (grade<1 || grade>5){
                    cout<<"Оценка может быть только от 1 до 5. Попробуйте снова! -";
                    cin>>grade;
                }
                Student st1=journal.searchStudentReturnStudent(name);
                journal.addGradeAtStudent(st1, grade);
                break;
            }
            case 4: {
                for (int i=0;i<COUTNSTUDENTS;i++){
                    int* buf=new int[students->getCountGrades()];
                    buf=journal.getStudents()[i].getGrates();
                    journal.getStudents()[i].setGradeAtQuater(buf);
                }
                cout<<"Четвертные оценки выставлены"<<endl;
                break;
            }
            case 5: {
                for (int i=0; i<COUTNSTUDENTS;i++){
                    int* buf=new int[4];
                    buf=journal.getStudents()[i].getGratesAtQuater();
                }
                cout<<"Годовые оценки выставлены"<<endl;
                break;
            }
            case 6: {
                string name;
                cout<<"Введите фамилию и имя студента"<<endl;
                cin>>name;
                while (!journal.searchStudent(name)){
                    if (!journal.searchStudent(name)){
                        cout<<"Студента с таким именем не найдено, попробуйте снова"<<endl;
                        cin>>name;
                    }
                }
                Student st1=journal.searchStudentReturnStudent(name);
                st1.showInfo();
                break;
            }
            case 7: {
                for (int i=0; i<COUTNSTUDENTS;i++){
                    journal.getStudents()[i].showInfo();
                }
                break;
            }
            case 8: {
                string name="";
                cout<<"Введите название файла -";
                cin>>name;
                name=name+".csv";
                writeInFile(journal, name);
                break;
            }
            case 9:{
                string name="";
                cout<<"Введите название файла -";
                cin>>name;
                name=name+".csv";
                journal=readFromFile(name);
            }
                
        }
    } while (num!=100);
    

        
        
    
    
    
}
