using System;
using System.IO;
using System.Text.RegularExpressions;

//Задание 1
/*
class Program
{
    static void Main()
    {
        Console.WriteLine("Введите путь к директории:");
        string directoryPath = Console.ReadLine();

        if (!Directory.Exists(directoryPath))
        {
            Directory.CreateDirectory(directoryPath);
            Console.WriteLine("Директория создана.");
        }
        else
        {
            Console.WriteLine("Директория уже существует.");
        }

        string file1Path = Path.Combine(directoryPath, "file1.txt");
        string file2Path = Path.Combine(directoryPath, "file2.txt");

        File.WriteAllText(file1Path, "Это пример содержимого файла 1.");
        File.WriteAllText(file2Path, "Здесь находится некоторый текст второго файла.");

        Console.WriteLine("Файлы созданы и заполнены.");

        Console.WriteLine("Введите слово для поиска в файлах:");
        string searchWord = Console.ReadLine();

        if (SearchWordInFile(file1Path, searchWord))
        {
            Console.WriteLine($"Слово \"{searchWord}\" найдено в файле 1.");
        }
        else
        {
            Console.WriteLine($"Слово \"{searchWord}\" не найдено в файле 1.");
        }

        if (SearchWordInFile(file2Path, searchWord))
        {
            Console.WriteLine($"Слово \"{searchWord}\" найдено в файле 2.");
        }
        else
        {
            Console.WriteLine($"Слово \"{searchWord}\" не найдено в файле 2.");
        }
    }

    static bool SearchWordInFile(string filePath, string searchWord)
    {
        string fileContent = File.ReadAllText(filePath);
        return fileContent.Contains(searchWord);
    }
}
*/

//Задание 2

class Program
{
    static void Main()
{
    string inputString = "Hi! My name is Elena, im living in Pushkin street, 23! I'm 19 years old! ";

    string resultString = Regex.Replace(inputString, @"[\d\W_]+", "");

    Console.WriteLine("Исходная строка: " + inputString);
    Console.WriteLine("Результат: " + resultString);
}
}

