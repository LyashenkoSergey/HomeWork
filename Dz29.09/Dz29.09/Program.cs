
using System;
using static System.Runtime.InteropServices.JavaScript.JSType;

internal class Program
{
    private static void Main(string[] args)
    {
        //Задача 1
        /*
        void checkNum(int num)
        {
            if (num % 3 == 0)
            {
                Console.WriteLine("Fizz");
            }
            else if (num % 5 == 0)
            {
                Console.WriteLine("Buzz");
            }
            else if (num % 3 == 0 && num % 5 == 0)
            {
                Console.WriteLine("Fizz Buzz");
            }
            else if (num % 3 != 0 && num % 5 != 0)
                Console.WriteLine(num);
        }
        
      
        int num;
        do
        {
            Console.WriteLine("Введите целое число в диапазоне от 1 до 100");
            num = Convert.ToInt32(Console.ReadLine());
            if (num > 0 && num < 101)
            {
                checkNum(num);
            }
            else
                Console.WriteLine("Число вне диапазона");
        }
        while (num < 1 && num > 100);


        // Задача 2

        num = 0;
        float numPercent = 0f;
        Console.Write("Введите целое число -> ");
        num = Convert.ToInt32(Console.ReadLine());
        Console.Write("Введите какой процент от этого числа вы хотите посчитать -> ");
        numPercent = Convert.ToInt32(Console.ReadLine());
        if (numPercent > 0)
        {
            Console.WriteLine($"{numPercent} процентов от числа {num}, составит {num / 100 * numPercent}");
        }
        else
            Console.WriteLine("Хорошая шутка, сам понял, что ввел!)");
        
        // Задача 3

        do
        {
            string str1 = "", str2 = "";
            for (int i = 0; i < 4; i++)
            {
                Console.WriteLine("Введите число ");
                str2 = Console.ReadLine();
                str1 += str2;
            }
            Console.WriteLine(Convert.ToInt32(str1));
        }
        while (Console.ReadKey().Key != ConsoleKey.Escape);

        // Задача 4

        do
        {
            Console.WriteLine("Введите шестизначное число ");
            string str = Console.ReadLine();
            if (str.Length != 6)
            {
                Console.WriteLine("Я же сказал шестизначное! попробуешь в следующий раз");
            }
            else
            {
                Console.WriteLine("Введите номера разрядов, которые вы хотите поменять");
                int num1 = Convert.ToInt32(Console.ReadLine());
                int num2 = Convert.ToInt32(Console.ReadLine());
                int bufNum = Convert.ToInt32(str);
                int bufNum1;
                int[] buf = new int[6];
                for (int i = 5; i >= 0; i--)
                {
                    bufNum1 = bufNum % 10;
                    bufNum /= 10;
                    buf[i] = bufNum1;
                }
                bufNum = buf[num1-1];
                buf[num1-1] = buf[num2-1];
                buf[num2-1] = bufNum;
                for(int i = 0; i < 6; i++)
                {
                    Console.Write(buf[i]);
                }

                
            }
            
        } while (Console.ReadKey().Key != ConsoleKey.Escape);

        // Задача 5
        do
        {
            Console.WriteLine("Введите дату (день.месяц.год)");
            string s = Console.ReadLine();
            string[] subs = s.Split('.');
            string[] months = { "Январь", "Февраль", "Март", "Апрель", "Май", "Июнь", "Июль", "Август", "Сентябрь", "Октябрь", "Ноябрь", "Декабрь" };
            string[] season = { "Winter", "Spring", "Summer", "Autumn" };
            int day = Convert.ToInt32(subs[0]);
            int month = Convert.ToInt32(subs[1]);
            int year = Convert.ToInt32(subs[2]);
            DateTime date = new DateTime(year,month,day);
            if (month == 12 || month == 1 || month==2)
            {
                Console.WriteLine($"{s} была {season[0]} {date.DayOfWeek} ");
            }
            else if (month > 2 && month < 6)
            {
                Console.WriteLine($"{s} была {season[1]} {date.DayOfWeek} ");
            }
            else if (month > 5 && month < 9)
            {
                Console.WriteLine($"{s} была {season[2]} {date.DayOfWeek} ");
            }
            else
                Console.WriteLine($"{s} была {season[3]} {date.DayOfWeek} ");





        } while (Console.ReadKey().Key != ConsoleKey.Escape);
        
        // Задача 6
        do
        {
            Console.WriteLine("Введите температуру");
            double temperature= Convert.ToDouble(Console.ReadLine());
            Console.WriteLine("Если хотите перевести температуру из С в F нажмите 1");
            Console.WriteLine("Если хотите перевести температуру из F в C нажмите 2");
            int choise = Convert.ToInt32(Console.ReadLine());
            double result;
            if (choise == 1)
            {
                result = temperature * 9 / 5 + 32;
                Console.WriteLine($"Температура по Фаренгейту равна: {result}");
            }
            else if (choise == 2)
            {
                result = (temperature - 32) * 5 / 9;
                Console.WriteLine($"Температура по Цельсию равна: {result}");
            }
            else
                Console.WriteLine("Ошибка");
        } while (Console.ReadKey().Key != ConsoleKey.Escape);
*/
        // Задача 7
        do
        {
            Console.WriteLine("Введите два числа");
            int data1 = Convert.ToInt32(Console.ReadLine());
            int data2 = Convert.ToInt32(Console.ReadLine());
            if (data1 > data2)
            {
                int temp = data1;
                data1 = data2;
                data2 = temp;
            }
            for (int i = data1; i <= data2; i++)
            {
                if (i % 2 == 0)
                {
                    Console.Write($"{i} ");
                }
            }
            

        } while (Console.ReadKey().Key != ConsoleKey.Escape);
    }
}