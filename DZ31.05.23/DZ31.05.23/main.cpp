#include <iostream>

using namespace std;




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
    void showInfo(){
        cout<<numerator<<"/"<<denomirator<<endl;
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
}
   


int main() {
    
    return 0;
}
