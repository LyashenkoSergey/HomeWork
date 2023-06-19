#pragma once
#include <iostream>
#include <string>

using namespace std;

class Abonent{
private:
    char* fio;
    char* phone;
public:
    Abonent();
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
    void operator =(const Abonent& abonent){
          delete[] this->fio;
          delete[] this->phone;
          this->fio = new char[strlen(abonent.fio) + 1];
          strcpy(this->fio, abonent.fio);
          this->phone = new char[strlen(abonent.phone) + 1];
          strcpy(this->phone, abonent.phone);
      }
    bool operator ==(Abonent& abonent){
        if (
            this->fio==abonent.fio &&
            this->phone==abonent.phone){
                return true;
            }
        else return false;
    
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
    Abonent SearchAbonent(char* fio){
        size_t size = strlen(fio);
        Abonent n;
        for (int i = 0; i < number; i++){
            if (strncmp(abonent[i].getFio(), fio, size) == 0){
                n = abonent[i];
                break;
            }
        }
        return n;
    }


    //добавление абонента
    void AddAbonent(Abonent& abonent){
        Abonent* buf=new Abonent[number+1];
        for (int i =0; i<number;i++){
            buf[i]=this->abonent[i];
        }
        buf[number]=abonent;
        delete [] this->abonent;
        this->abonent=buf;
        number++;
    }
        

    //удаление абонента
    void DelAbonent(Abonent& abonent){
        if (this->abonent!=nullptr){
            Abonent* buf=new Abonent[number-1];
            int num=-1;
            for (int i =0; i<number;i++){
                if (this->abonent[i]==abonent){
                    num=i;
                    break;
                }
            }
            if (num == -1) {
                return ;
            }
            for (int i=0; i<num;i++){
                buf[i]=this->abonent[i];
            }
            for (int i=num+1;i<number;i++){
                buf[i-1]=this->abonent[i];
            }
            delete[] this->abonent;
            this->abonent=buf;
            number--;
        }
        else cout<<"Phonebook is empty"<<endl;
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

