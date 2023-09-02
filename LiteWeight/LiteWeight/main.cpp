#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

    /*Паттерн легковес.
        На производстве есть подразделения со своими отделами, а в каждом отделе уникальный сотрудник.
    */

//Общие св-ва отделов
struct Shared {
    string department;
    string position;

    Shared(const string& dep, const string& pos) {
        department = dep;
        position = pos;
    }
};

struct Unique {
    string id;
    string name;

    Unique(const string& id, const string& name) {
        this->id = id;
        this->name = name;
    }

};

class LiteWeight {
private:
    Shared* shared;

public:
    LiteWeight(const Shared* shared): shared(new Shared(*shared))
    {
    }
    LiteWeight(const LiteWeight& liteWeight) : shared(new Shared(*liteWeight.shared))
    {
    }
    ~LiteWeight() {
        delete shared;
    }
    void add(const Unique& unique) const
    {
        cout << "Отображаем новые данные: общие - "
            << shared->department << " _ "
            << shared->position << "и уникальные - "
            << unique.id << " _ "
            << unique.name << "." << endl;
    }
};

class LiteWeightFactory
{
private:
    map<string, LiteWeight> liteweights;
    string getKey(const Shared& shared)
    {
        return shared.department + " _ " + shared.position;
    }
public:
    LiteWeightFactory(initializer_list<Shared> shareds)
    {
        for (const Shared& shared : shareds) {
            this->liteweights.insert(make_pair<string, LiteWeight>(this->getKey(shared), LiteWeight(&shared)));
        }
    }

    LiteWeight getLiteWeight(const Shared& shared)
    {
        string key = this->getKey(shared);
        if (this->liteweights.find(key) == this->liteweights.end()) {
            cout << "Фабрика легковесов: Общий объект по ключу " << key << " не найден. Создаем новый." << endl;
            this->liteweights.insert(make_pair(key, LiteWeight(&shared)));
        }
        else {
            cout << "Фабрика легковесов: извлекаем данные из имеющихся записей по ключу " << key << endl;
        }
        return this->liteweights.at(key);
    }
    void listLiteWeight() {
        int count = this->liteweights.size();
        cout << endl << "Фабрика легковесов: Всего " << count << " записей:" << endl;
        for (pair<string, LiteWeight> pair : this->liteweights) {
            cout << pair.first << endl;
        }
    }

};

void addEmployee(LiteWeightFactory& ll, const string& department, const string& position,
    const string& id, const string& name)
{
    const LiteWeight& liteweigh = ll.getLiteWeight({ department,position });
    liteweigh.add({ id, name });
}



int main()
{
    setlocale(LC_ALL, "rus");

    LiteWeightFactory* factory = new LiteWeightFactory({
        {"Логистика", "Отдел рекламы"},
        {"Логистика", "Отдел заказов"},
        {"Дизайнеры", "Отдел рекламы"},
        {"Дизайнеры", "Отдел разработчиков"}
        });
    factory->listLiteWeight();

    addEmployee(*factory, "Логистика", "Отдел заказов", "Александр", "215");
    addEmployee(*factory, "Дизайнеры", "Отдел рекламы", "Виктор", "729");

    factory->listLiteWeight();
    delete factory;

}

