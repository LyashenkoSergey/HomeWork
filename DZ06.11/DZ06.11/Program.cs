namespace DZ06._11;

public class Program
{
    public static void Main(string[] args)
    {
        /*
        do
        {
            //Задание 1
            Console.WriteLine("Выберите направление перевода:");
            Console.WriteLine("1. Из десятичной в двоичную");
            Console.WriteLine("2. Из двоичной в десятичную");
            Console.WriteLine("3. Выход");


            string choice = Console.ReadLine();

            switch (choice)
            {
                case "1":
                    ConvertDecimalToBinary();
                    break;
                case "2":
                    ConvertBinaryToDecimal();
                    break;
                case "3":
                    Environment.Exit(0);
                    break;
                default:
                    Console.WriteLine("Некорректный выбор");
                    break;
            }



        } while (Console.ReadKey().Key != ConsoleKey.Escape);
    }
    static void ConvertDecimalToBinary()
        {
            Console.WriteLine("Введите число в десятичной системе:");
            if (int.TryParse(Console.ReadLine(), out int number))
            {
                string binary = Convert.ToString(number, 2);
                Console.WriteLine("Результат перевода в двоичную систему: " + binary);
            }
            else
            {
                Console.WriteLine("Некорректный ввод числа");
            }
        }

        static void ConvertBinaryToDecimal()
        {
            Console.WriteLine("Введите число в двоичной системе:");
            string binary = Console.ReadLine();

            if (!IsValidBinary(binary))
            {
                Console.WriteLine("Некорректный ввод числа");
                return;
            }

            int decimalNumber = Convert.ToInt32(binary, 2);
            Console.WriteLine("Результат перевода в десятичную систему: " + decimalNumber);
        }

        static bool IsValidBinary(string binary)
        {
            foreach (char digit in binary)
            {
                if (digit != '0' && digit != '1')
                {
                    return false;
                }
            }
            return true;
        }


        //Задание 2

        do
        {
            string[] digits = { "zero", "one", "two", "three", "four", "five", "six",
    "seven", "eitht", "nine" };

            Console.WriteLine("Введите слово от нуля до девяти:");
            string word = Console.ReadLine();

            int index = Array.IndexOf(digits, word.ToLower());

            if (index == -1)
            {
                Console.WriteLine("Некорректное слово");
            }
            else
            {
                Console.WriteLine("Цифра: " + index);
            }

        } while (Console.ReadKey().Key != ConsoleKey.Escape);

        */

        //Задание 3
        /*
        do
        {
            try
            {
                Console.WriteLine("Введите номер паспорта:");
                string number = Console.ReadLine();

                Console.WriteLine("Введите Имя владельца:");
                string name = Console.ReadLine();

                Console.WriteLine("Введите Фамилию владельца:");
                string lastName = Console.ReadLine();

                Console.WriteLine("Введите дату выдачи паспорта (в формате дд/мм/гггг):");
                DateTime date = DateTime.ParseExact(Console.ReadLine(), "dd/MM/yyyy", null);

                Passport passport = new Passport(number, name, lastName, date);
                Console.WriteLine("Заграничный паспорт успешно создан.");
            }
            catch (Exception ex)
            {
                Console.WriteLine("Ошибка: " + ex.Message);
            }
        } while (Console.ReadKey().Key != ConsoleKey.Escape);




    }
    public class Passport
    {
        public string Number { get; set; }
        public string Name { get; set; }
        public string LastName { get; set; }
        public DateTime Date { get; set; }

        public Passport(string number, string name, string lastName, DateTime date)
        {
            if (string.IsNullOrWhiteSpace(number))
            {
                throw new ArgumentException("Номер паспорта не может быть пустым.");
            }

            if (string.IsNullOrWhiteSpace(name))
            {
                throw new ArgumentException("Поле Имя не может быть пустым.");
            }
            if (string.IsNullOrWhiteSpace(lastName))
            {
                throw new ArgumentException("Поле Имя не может быть пустым.");
            }

            if (DateTime.Compare(date, DateTime.Now) > 0)
            {
                throw new ArgumentException("Дата выдачи паспорта не может быть в будущем.");
            }

            Number = number;
            Name = name;
            LastName = lastName;
            Date = date;
        }
        */

        //Задание 4

        do
        {
            try
            {
                Console.WriteLine("Введите логическое выражение:");
                string input = Console.ReadLine();

                bool result = EvaluateExpression(input);
                Console.WriteLine("Результат: " + result);
            }
            catch (Exception ex)
            {
                Console.WriteLine("Ошибка: " + ex.Message);
            }

            Console.ReadKey();

        } while (Console.ReadKey().Key != ConsoleKey.Escape);
        }

        static bool EvaluateExpression(string input)
        {
            int operand1, operand2;
            string @operator;

            ParseExpression(input, out operand1, out @operator, out operand2);

            switch (@operator)
            {
                case ">":
                return operand1 > operand2;
                break;
            case "<":
                return operand1 < operand2;
                break;
            case ">=":
                return operand1 >= operand2;
                break;
            case "<=":
                return operand1 <= operand2;
                break;
            case "==":
                return operand1 == operand2;
                break;
            case "!=":
                return operand1 != operand2;
                break;
            default:
                throw new ArgumentException("Некорректный оператор");
            }
        }

        static void ParseExpression(string input, out int operand1, out string @operator, out int operand2)
        {
            string[] parts = input.Split(' ');

            if (parts.Length != 3)
            {
                throw new ArgumentException("Некорректное выражение");
            }

            if (!int.TryParse(parts[0], out operand1))
            {
                throw new ArgumentException("Некорректный операнд");
            }

            @operator = parts[1];

            if (!int.TryParse(parts[2], out operand2))
            {
                throw new ArgumentException("Некорректный операнд");
            }
        }

    
    
    
}
















