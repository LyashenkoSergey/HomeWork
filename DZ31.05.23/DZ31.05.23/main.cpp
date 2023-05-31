#include "param.h"


#define test1

#ifdef test1
class Drob{
private:
    float numerator;
    float denomirator;
public:
    void setNumerator(float numerator){
        this->numerator=numerator;
    }
    void setDenominator(float denominator){
        if (denomirator==0){
            cout<<"Error! Denominator can't be zero!";
        }
        else{
            this->denomirator=denomirator;
        }
    }
    float getNumerator(){
        return numerator;
    }
    float getDenominator(){
        return denomirator;
    }
};

Drob summDrob(Drob drob1, Drob drob2){
    Drob drob3;
    if (drob1.getDenominator()==drob2.getDenominator()){
        drob3.setNumerator(drob1.getNumerator()+drob2.getNumerator());
        drob3.setDenominator(drob1.getDenominator());
    }
    else{
        drob3.setDenominator(drob1.getDenominator()*drob2.getDenominator());
        drob3.setNumerator((drob1.getNumerator()*drob2.getDenominator())+drob2.getNumerator()*drob1.getDenominator());
        }
    return drob3;
};

Drob differenceDrob(Drob drob1, Drob drob2){
    Drob drob3;
    if (drob1.getDenominator()==drob2.getDenominator()){
        drob3.setNumerator(drob1.getNumerator()-drob2.getNumerator());
        drob3.setDenominator(drob1.getDenominator());
    }
    else{
        drob3.setDenominator(drob1.getDenominator()*drob2.getDenominator());
        drob3.setNumerator((drob1.getNumerator()*drob2.getDenominator())-drob2.getNumerator()*drob1.getDenominator());
        }
    return drob3;
};

Drob multiDrob(Drob drob1, Drob drob2){
    Drob drob3;
        drob3.setDenominator(drob1.getDenominator()*drob2.getDenominator());
        drob3.setNumerator(drob1.getNumerator()*drob2.getNumerator());
    return drob3;
};

Drob divisionDrob(Drob drob1, Drob drob2){
    Drob drob3;
        drob3.setDenominator(drob1.getDenominator()*drob2.getNumerator());
        drob3.setNumerator(drob1.getNumerator()*drob2.getDenominator());
    return drob3;
};
/*
#elif test2

class PhoneBook{
private:
    static int countAb=0;
    Abonent* array=NULL;
public:
    Abonent* createPhoneBook(){
        array=new Abonent[countAb];
        return array;
    }
    void addAbonent(Abonent abonent){
        Abonent* buf=new Abonent[countAb+1];
        for (int i=0;i<countAb;i++){
            buf[i]=array[i];
        }
        buf[countAb]=abonent;
        delete[] array;
        array=buf;
        countAb++;
    }
   // void deleteAbonent(
    void showAllAbonent(){
        for (int i=0; i<countAb;i++){
            array[i].showInfo();
        }
    }
}
class Abonent::Phonebook{
private:
    int numberAb=0;
    string fio="";
    string homePhone="0";
    string workPhone="0";
    string mobilePhone="0";
    string suppInfo="";
    
public:
    Abonent(string fio,string homePhone,string workPhone,string mobilePhone);{
        ++numberAb;
    }
    void setFio(string fio){
        this->fio=fio;
    }
    void setHomePhone(string homePhone){
        this->homePhone=homePhone;
    }
    void setWorkPhone(string workPhone){
        this->workPhone=workPhone;
    }
    void setMobilePhone(string mobilePhone){
        this->mobilePhone=mobilePhone;
    }
    void setSuppInfo(string suppInfo){
        this->suppInfo=suppInfo;
    }
    int getNumberAbonent(){
        return numberAb;
    }
    string getFio(){
        return fio;
    }
    string getHomePhone(){
        return homePhone;
    }
    string getWorkPhone(){
        return workPhone;
    }
    string getMobilePhone(){
        return mobilePhone;
    }
    string getSuppInfo(){
        return suppInfo;
    }
    void showInfo(){
        cout<<numberAb<<" "<<fio<<" "<<homePhone<<" "<<workPhone<<" "<<mobilePhone<<" "<<suppInfo<<";"<<endl;
    }
};*/
#endif

int main() {
    
    
    
    return 0;
}
