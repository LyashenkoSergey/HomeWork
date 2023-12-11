using System;
using System.Linq;



/*Задание 1
int[] numbers = { 2, 4, 1, 3, 90, 654, 900, 1024, 96, 51 };

var evenNumbers = numbers.Where(n => n % 2 == 0);
var oddNumbers = numbers.Where(n => n % 2 != 0);

Console.WriteLine("Even numbers:");
foreach (var e in evenNumbers)
{
Console.Write(e + " ");
}
Console.WriteLine();

Console.WriteLine("Odd numbers:");
foreach (var e in oddNumbers)
{
Console.Write(e + " ");
}
Console.WriteLine();
*/

//Задание 2

internal class Program
{
    private static void Main(string[] args)
    {
        string text = "Привет! Это голосовой помощник Олег! Оставьте свое сообщение!";

        var wordsWithO = text.Split(new char[] { ' ', '!', '?', ',', '.' }).Where(word => word.Contains('о') || word.Contains('т')).ToList();

        var wordsEndsWithEorK = text.Split(new char[] { ' ', '!', '?', ',', '.' }).Where(word => word.EndsWith('е') || word.EndsWith('к')).ToList();

        Console.WriteLine("Words with о or т: ");
        foreach (var e in wordsWithO)
        {
            Console.Write(e + " ");
        }
        Console.WriteLine();

        Console.WriteLine("Words ending with е or к:");
        foreach (var e in wordsEndsWithEorK)
        {
            Console.Write(e + " ");
        }
        Console.WriteLine();
    }
}