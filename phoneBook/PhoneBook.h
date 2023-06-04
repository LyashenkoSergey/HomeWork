#pragma once
#include <iostream>
#include <string>

using namespace std;

class Abonent{
private:
    char* fio;
    char* phone;
public:
    Abonent(char* fio, char* phone){
        this->fio = new char[strlen(fio) + 1];
        this->fio=fio;
        this->phone = new char[strlen(phone) + 1];
        this->phone=phone;
    }
    Abonent(const Abonent& abonent){
        this->fio = new char[strlen(abonent.fio) + 1];
        this->fio=abonent.fio;
        this->phone = new char[strlen(abonent.phone) + 1];
        this->phone=abonent.phone;

    }
    void setFio(char* fio){
        delete[] this->fio;
        this->fio = new char[strlen(fio) + 1];
        this->fio=fio;
    }
    void setPhone(char* phone){
        delete[] this->phone;
        this->phone = new char[strlen(phone) + 1];
        this->phone=phone;
    }
    char* getFio(){
        return fio;
    }
    char* getPhone(){
        return phone;
    }
    void showAbonent(){
        cout<<fio<<" : "<<phone<<endl;
    }
    ~Abonent(){
        delete[] fio;
        delete[] phone;
    }
};




class PhoneBook {
private:
    static int number;
    Abonent* abonent;
public:
    
    PhoneBook();
    PhoneBook(const Abonent& abonent){
        number++;
        this->abonent = new Abonent(abonent);
    }
    
    //конструктор копирования
    PhoneBook(const PhoneBook& phonebook){
        number++;
        this->abonent=new Abonent(*phonebook.abonent);
    }

    //поиск абонента
    int SearchAbonent(PhoneBook* phonebook, char const* fio){
        size_t size=strlen(fio);
        bool flag=false;
        int n=-1;
        for (int i=0; i<number;i++){
            if (phonebook->abonent[i].getFio()[0]==fio[0]){
                flag=true;
                n=i;
                for (int j=1; j<size; j++){
                    if (phonebook->abonent[i].getFio()[j]!=fio[j]){
                        flag=false;
                        n=-1;
                        break;
                    }
                }
            }
        }
        return n;
    }

    //добавление абонента
    void AddAbonent(PhoneBook*& phonebook, Abonent*& abonent){
        PhoneBook* buf=new PhoneBook[number+1];
        for (int i =0; i<number;i++){
            buf[i]=phonebook[i];
        }
        buf[number]=PhoneBook(*abonent);
        delete [] phonebook;
        phonebook=buf;
        number++;
    }
        

    //удаление абонента
    void DelAbonent(PhoneBook*& phonebook, Abonent*& abonent){
        PhoneBook* buf=new PhoneBook[number-1];
        int num=-1;
        for (int i =0; i<number;i++){
            if (phonebook[i].abonent==abonent){
                num=i;
            }
        }
        if (num == -1) {
            return ;
        }
        for (int i=0; i<num;i++){
            buf[i]=phonebook[i];
        }
        for (int i=num+1;i<number;i++){
            buf[i-1]=phonebook[i];
        }
        delete [] phonebook;
        phonebook=buf;
        number--;
    }
   

    //печать книги абонентов
    void showPhoneBook(){
        for (int i=0;i<number;i++){
           abonent[i].showAbonent();
        }
    }

    int getNumber(){
        return number;
    }
    Abonent* getAbonent(){
        return abonent;
    }
    
    //деструктор
    ~PhoneBook(){
        delete[] abonent;
    }

};
int PhoneBook::number=0;
