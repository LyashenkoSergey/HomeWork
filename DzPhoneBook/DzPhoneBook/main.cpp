/*Создайте приложение «Телефонная книга». Необходимо хранить данные об абоненте
(ФИО, домашний телефон, рабочий телефон, мобильный телефон, дополнительная информация о контакте)
внутри соответствующего класса.

Наполните класс переменными - членами, функциями членами, конструкторами, inline - функциями - членами,
используйте инициализаторы, реализуйте деструктор.
Обязательно необходимо выделять динамически память под ФИО.
Предоставьте пользователю возможность добавлять новых абонентов, удалять абонентов,
искать абонентов по ФИО, показывать всех абонентов.*/


#include "param.h"


int main()
{
    int counter, buf;
    PhoneBook phonebook1;
    char* fio=new char[50]{};
    char* phone=new char[12]{};
    
    do {
        cout<<"Телефонная Книга"<<endl;
        cout<<"Нажмите \"1\", чтобы показать всех абонентов"<<endl;
        cout<<"Нажмите \"2\", чтобы добавить абонента"<<endl;
        cout<<"Нажмите \"3\", чтобы удалить абонента"<<endl;
        cout<<"Нажмите \"4\", чтобы искать абонента"<<endl;
        cout<<"Нажмите \"5\", чтобы выйти из телефонной книги"<<endl;
        
        cin>>counter;
        switch (counter){
            case 1:
                phonebook1.showPhoneBook();
                break;
            case 2:
                cout<<"Введите ФИО - ";
                cin.ignore();
                cin.getline(fio, 50);
                cout<<"Введите номер телефона - ";
                cin.getline(phone, 12);
                Abonent abonent(fio,phone);
                phonebook1.AddAbonent(phonebook1,abonent);
                break;
            case 3:
                cout<<"Введите ФИО - ";
                cin.ignore();
                cin.getline(fio, 50);
                buf=phonebook1.SearchAbonent(phonebook1, fio);
                if(buf==-1){
                    cout<<"Абонент не найден"<<endl;
                }
                else{
                    phonebook1.DelAbonent(phonebook1, phonebook1.getAbonent()[buf]);
                }
                break;
            case 4:
                cout<<"Введите ФИО - ";
                cin.ignore();
                cin.getline(fio, 50);
                buf=phonebook1.SearchAbonent(phonebook1, fio);
                if (buf!=-1){
                    phonebook1.getAbonent()[buf].showAbonent();
                }
                else cout<<"Абонент не найден";
                break;
            default:
                break;
        }
        
        
        
        
        
        
        
        system("pause");
        
    }
    while (counter!=5);
    
}


