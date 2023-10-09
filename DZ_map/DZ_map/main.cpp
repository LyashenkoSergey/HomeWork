#include <iostream>
#include <fstream>
#include <map>

using namespace std;

// Функция для поиска слова в словаре
void searchWord(const map<string, string>& dictionary) {
    string word;
    cout << "Введите слово для поиска: ";
    cin >> word;

    auto iter = dictionary.find(word); // Ищем слово в словаре

    if (iter != dictionary.end()) {
        cout << "Значение слова \"" << iter->first << "\": " << iter->second << endl;
    }
    else {
        cout << "Слово \"" << word << "\" не найдено в словаре." << endl;
    }
}

// Функция для добавления слова в словарь
void addWord(map<string, string>& dictionary) {
    string word, value;
    cout << "Введите слово для добавления: ";
    cin >> word;
    cout << "Введите значение слова: ";
    cin >> value;

    dictionary.insert(make_pair(word, value));
    cout << "Слово \"" << word << "\" добавлено в словарь." << endl;
}

// Функция для удаления слова из словаря
void removeWord(map<string, string>& dictionary) {
    string word;
    cout << "Введите слово для удаления: ";
    cin >> word;

    size_t count = dictionary.erase(word); // Удаляем слово из словаря

    if (count > 0) {
        cout << "Слово \"" << word << "\" удалено из словаря." << endl;
    }
    else {
        cout << "Слово \"" << word << "\" не найдено в словаре." << endl;
    }
}

// Функция для редактирования слова в словаре
void editWord(map<string, string>& dictionary) {
    string word, value;
    cout << "Введите слово для редактирования: ";
    cin >> word;

    auto iter = dictionary.find(word); // Ищем слово в словаре

    if (iter != dictionary.end()) {
        cout << "Введите новое значение слова \"" << iter->first << "\": ";
        cin >> value;
        iter->second = value;
        cout << "Значение слова \"" << iter->first << "\" обновлено." << endl;
    }
    else {
        cout << "Слово \"" << word << "\" не найдено в словаре." << endl;
    }
}

// Функция для чтения словаря из файла
void readDictionary(map<string, string>& dictionary) {
    string filename;
    cout << "Введите имя файла для чтения словаря: ";
    cin >> filename;

    ifstream in(filename);
    if (in.is_open()) {
        string line;
        while (getline(in, line)) {
            size_t pos = line.find(':');
            if (pos != string::npos) {
                string word = line.substr(0, pos);
                string value = line.substr(pos + 1);
                dictionary.insert(make_pair(word, value));
            }
        }
        in.close();
        cout << "Словарь успешно загружен из файла." << endl;
    }
    else {
        cout << "Ошибка открытия файла " << filename << "." << endl;
    }
}

// Функция для записи словаря в файл
void writeDictionary(const map<string, string>& dictionary) {
    string filename;
    cout << "Введите имя файла для записи словаря: ";
    cin >> filename;

    ofstream out(filename);
    if (out.is_open()) {
        for (const auto& pair : dictionary) {
            out << pair.first << ":" << pair.second << endl;
        }
        out.close();
        cout << "Словарь успешно записан в файл." << endl;
    }
    else {
        cout << "Ошибка открытия файла " << filename << "." << endl;
    }
}

int main() {
    map<string, string> dictionary;
    
    int choice;
    while (true) {
        cout << "Меню:" << endl;
        cout << "1. Поиск слова" << endl;
        cout << "2. Добавление слова" << endl;
        cout << "3. Удаление слова" << endl;
        cout << "4. Редактирование слова" << endl;
        cout << "5. Чтение словаря из файла" << endl;
        cout << "6. Запись словаря в файл" << endl;
        cout << "0. Выход" << endl;
        
        cout << "Введите номер операции: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                searchWord(dictionary);
                break;
            case 2:
                addWord(dictionary);
                break;
            case 3:
                removeWord(dictionary);
                break;
            case 4:
                editWord(dictionary);
                break;
            case 5:
                readDictionary(dictionary);
                break;
            case 6:
                writeDictionary(dictionary);
                break;
            case 0:
                return 0;
            default:
                cout << "Ошибка: неверный номер операции." << endl;
        }
        
        cout << endl;
    }
    
    return 0;
}

