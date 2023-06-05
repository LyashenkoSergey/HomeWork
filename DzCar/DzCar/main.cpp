/*
 создать класс машина
 описан
 марка
 цвет
 гос номер(уникальный)

 создать класс парковка
 реализовать метод добавления машин и удаления по гос-номеру

 предположить что мы можем копировать машину (но при
 копировании новая машину будет с уникальным гос номером)
 */

#include <iostream>

using namespace std;

class Car{
private:
    string model;
    string color;
    char* number=nullptr;
    char* letter=new char[]{'A','B','E','K','H','M','O','P','C','T','X'};
    static char* uniqNumber;
    int i=0,j=0,k=0;
public:
    
    Car(string model, string color){
        this->model=model;
        this->color=color;
        this->number=new char[6]{};
        this->number=generateUniqNumber(uniqNumber);
    }

    char* generateUniqNumber(char*& uniqNumber){
        if (uniqNumber[3] == '9') {
                   if (uniqNumber[2] == '9') {
                       if (uniqNumber[1]=='9'){
                           if (uniqNumber[5]=='X'){
                               if (uniqNumber[4]=='X'){
                                   uniqNumber[0]=letter[++k];
                                   uniqNumber[1]='0';
                                   uniqNumber[2]='0';
                                   uniqNumber[3]='0';
                                   uniqNumber[4]=letter['0'];
                                   uniqNumber[4]=letter['0'];
                                   i=-1;
                                   j=-1;
                               }
                               else{
                                   uniqNumber[4]=letter[++j];
                                   uniqNumber[1]='0';
                                   uniqNumber[2]='0';
                                   uniqNumber[3]='0';
                                   uniqNumber[5]=letter[0];
                                   i=-1;
                               }
                           }
                           else{
                               uniqNumber[5]=letter[++i];
                               uniqNumber[1]='0';
                               uniqNumber[2]='0';
                               uniqNumber[3]='0';
                           }
                       }
                       else{
                           uniqNumber[1]++;
                           uniqNumber[2]='0';
                           uniqNumber[3]='0';
                       }
                       
                   } else {
                       uniqNumber[2]++;
                       uniqNumber[3] = '0';
                   }
               } else {
                   uniqNumber[3]++;
               }

        return uniqNumber;
    }
    
    Car(const Car& car){
        this->model=car.model;
        this->color=car.color;
        this->number=new char[6]{};
        this->number=generateUniqNumber(uniqNumber);
    }
    
    char* getNumber(){
        return number;
    }
    
    ~Car();
    
};
char* Car::uniqNumber=new char[]{'A','0','0','0','A','A'};

class Parking {
private:
    Car* cars=nullptr;
    int numCars = 0;

public:
    Parking();
    Parking(Car& car){
        addCar(car);
    }
    void addCar(Car& car){
        if (cars==nullptr){
            cars=new Car[1];
            cars[0] = car;
            numCars = 1;
        }
        else {
            Car* buf = new Car[numCars + 1];
            for (int i = 0; i < numCars; i++) {
                buf[i] = cars[i];
            }
            buf[numCars] = car;
            delete[] cars;
            cars = buf;
            numCars++;
        }
    }
    void deleteCar(char* number){
        bool flag=false;
        int n=-1;
        if (numCars==0) cout<<"Parking is empty"<<endl;
        else{
            for (int i=0;i<numCars;i++){
                if (cars[i].getNumber()[0]==number[0]){
                    flag = true;
                    for (int j=0; j<6;j++){
                        if (cars[i].getNumber()[j]!=number[j]){
                            flag=false;
                            break;
                        }
                    }
                    if (flag){
                        n=i;
                        break;
                    }
                }
            }
            if (n==-1) cout<<"Car is not found"<<endl;
            else{
                Car* buf = new Car[numCars - 1];
                for (int i = 0; i < n; i++) {
                    buf[i] = cars[i];
                }
                for (int i = n+1; i < numCars; i++) {
                    buf[i-1] = cars[i];
                }
                delete[] cars;
                cars = buf;
                numCars--;
            }
        }
    }
    ~Parking() {
            delete[] cars;
        }

  
};

int main() {

    return 0;
}
