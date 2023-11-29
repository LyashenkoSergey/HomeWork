using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;

class Dictionary
{
public string sourceLanguage;
public string targetLanguage;
public List<string> words;
public List<string> translations;

public Dictionary(string sourceLanguage, string targetLanguage)
{
    this.sourceLanguage = sourceLanguage;
    this.targetLanguage = targetLanguage;
    this.words = new List<string>();
    this.translations = new List<string>();
}

public void AddWord(string word, string translation)
{
    words.Add(word);
    translations.Add(translation);
}

public void ReplaceWord(string word, string translation, int index)
{
    words[index] = word;
    translations[index] = translation;
}

public void DeleteWord(string word)
{
    int index = words.IndexOf(word);
    words.RemoveAt(index);
    translations.RemoveAt(index);
}

public List<string> SearchTranslation(string word)
{
    List<string> result = new List<string>();
    for (int i = 0; i < words.Count; i++)
    {
        if (words[i] == word)
        {
            result.Add(translations[i]);
        }
    }
    return result;
    }
}
class Program
{
    static void ShowMenu()
    {
        Console.WriteLine("1. Создать новый словарь");
        Console.WriteLine("2. Добавить слово и перевод");
        Console.WriteLine("3. Заменить слово или перевод");
        Console.WriteLine("4. Удалить слово или перевод");
        Console.WriteLine("5. Найти перевод слова");
        Console.WriteLine("6. Экспортировать словарь");
        Console.WriteLine("7. Выход");
    }




    static void Main(string[] args)

    {
        Dictionary englishRussian = new Dictionary("English", "Russian");

        bool isRunning = true;

        while (isRunning)
        {
            ShowMenu();
            string choice = Console.ReadLine();

            switch (choice)
            {
                case "1":
                    // Создание нового словаря
                    Console.WriteLine("Введите исходный язык словаря:");
                    string sourceLang = Console.ReadLine();
                    Console.WriteLine("Введите целевой язык словаря:");
                    string targetLang = Console.ReadLine();
                    englishRussian = new Dictionary(sourceLang, targetLang);
                    Console.WriteLine("Словарь создан успешно!");
                    break;
                case "2":
                    // Добавление слова и перевода
                    Console.WriteLine("Введите слово:");
                    string word = Console.ReadLine();
                    Console.WriteLine("Введите перевод:");
                    string translation = Console.ReadLine();
                    englishRussian.AddWord(word, translation);
                    Console.WriteLine("Слово и перевод добавлены в словарь.");
                    break;
                case "3":
                    // Замена слова или перевода
                    Console.WriteLine("Введите слово, которое хотите заменить:");
                    string oldWord = Console.ReadLine();
                    Console.WriteLine("Введите новое слово:");
                    string newWord = Console.ReadLine();
                    Console.WriteLine("Введите новый перевод:");
                    string newTranslation = Console.ReadLine();
                    int index = englishRussian.words.IndexOf(oldWord);
                    if (index != -1)
                    {
                        englishRussian.ReplaceWord(newWord, newTranslation, index);
                        Console.WriteLine("Слово и перевод успешно заменены.");
                    }
                    else
                    {
                        Console.WriteLine("Слово не найдено в словаре.");
                    }

                    break;
                case "4":
                    // Удаление слова или перевода
                    Console.WriteLine("Введите слово или перевод для удаления:");
                    string wordOrTranslation = Console.ReadLine();
                    if (englishRussian.words.Contains(wordOrTranslation))
                    {
                        englishRussian.DeleteWord(wordOrTranslation);
                        Console.WriteLine("Слово успешно удалено из словаря.");
                    }
                    else if (englishRussian.translations.Contains(wordOrTranslation))
                    {
                        int indexToRemove = englishRussian.translations.IndexOf(wordOrTranslation);
                        englishRussian.words.RemoveAt(indexToRemove);
                        englishRussian.translations.RemoveAt(indexToRemove);
                        Console.WriteLine("Перевод успешно удален из словаря.");
                    }
                    else
                    {
                        Console.WriteLine("Слово или перевод не найдены в словаре.");
                    }

                    break;
                case "5":
                    // Поиск перевода слова
                    Console.WriteLine("Введите слово для поиска перевода:");
                    string searchWord = Console.ReadLine();
                    List<string> translations = englishRussian.SearchTranslation(searchWord);
                    if (translations.Count > 0)
                    {
                        Console.WriteLine("Переводы слова:");
                        foreach (string trans in translations)
                        {
                            Console.WriteLine(trans);
                        }
                    }
                    else
                    {
                        Console.WriteLine("Перевод не найден.");
                    }

                    break;
                case "6":
                    // Экспорт словаря
                    Console.WriteLine("Введите имя файла для экспорта словаря:");
                    string exportFileName = Console.ReadLine();
                    using (StreamWriter sw = new StreamWriter(exportFileName))
                    {
                        for (int i = 0; i < englishRussian.words.Count; i++)
                        {
                            sw.WriteLine(englishRussian.words[i] + " - " + englishRussian.translations[i]);
                        }
                    }
                    Console.WriteLine("Словарь успешно экспортирован в файл " + exportFileName);

                    break;
                case "7":
                    isRunning = false;
                    break;
                default:
                    Console.WriteLine("Неверный выбор. Попробуйте снова.");
                    break;
            }
        }
    }
}