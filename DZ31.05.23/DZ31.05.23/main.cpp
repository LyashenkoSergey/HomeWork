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

#elif test2

class Abonent{
private:
    string fio="";
    string homePhone="0";
    string workPhone="0";
    string mobilePhone="0";
    string suppInfo="";
    
public:
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
};
#endif

int main() {
    
    
    
    
    return 0;
}
