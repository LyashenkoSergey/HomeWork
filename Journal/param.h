#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#define rand() 0+rand()%10

string* LASTNAME = new string[]{ "Иванов ","Смирнов ","Кузнецов ",
        "Попов ","Федоров ","Новиков ","Михайлов ","Соколов ","Петров ","Васильев " };
string* FIRSTNAME = new string[]{ "Николай","Владимир","Виктор",
        "Александр","Сергей","Алексей","Владимир","Юрий","Михаил", "Александр" };

int COUTNSTUDENTS=10;

