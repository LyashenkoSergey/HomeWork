//Задание 1 и 2

using System.Data.Common;
using XO;
using System;

namespace XO
{
    public enum Player
    {
        None,
        Player,
        Computer
    }

    public class XOGame
    {
        private Player currentPlayer;
        private Player[,] board;
        private Random random;

        public XOGame()
        {
            currentPlayer = Player.None;
            board = new Player[3, 3];
            random = new Random();
        }

        public void Start()
        {
            currentPlayer = (Player)random.Next(1, 3);
            Console.WriteLine($"Игра началась. Игрок {(currentPlayer == Player.Player ? "1 (X)" : "2 (O)")} ходит первым.");

            while (true)
            {
                if (currentPlayer == Player.Player)
                {
                    PlayerMove();
                }
                else
                {
                    ComputerMove();
                }

                DrawBoard();

                Player winner = CheckWinner();
                if (winner != Player.None)
                {
                    Console.WriteLine(winner == Player.Player ? "Игрок 1 (X) победил!" : "Игрок 2 (O) победил!");
                    break;
                }

                if (IsBoardFull())
                {
                    Console.WriteLine("Ничья!");
                    break;
                }

                currentPlayer = currentPlayer == Player.Player ? Player.Computer : Player.Player;
            }
        }

        private void PlayerMove()
        {
            Console.WriteLine("Ваш ход. Введите номер строки (от 1 до 3):");
            int row = Convert.ToInt32(Console.ReadLine()) - 1;

            Console.WriteLine("Введите номер столбца (от 1 до 3):");
            int column = Convert.ToInt32(Console.ReadLine()) - 1;

            if (IsValidMove(row, column))
            {
                board[row, column] = Player.Player;
            }
            else
            {
                Console.WriteLine("Некорректный ход. Попробуйте еще раз.");
                PlayerMove();
            }
        }

        private void ComputerMove()
        {
            Console.WriteLine("Ход компьютера...");

            while (true)
            {
                int row = random.Next(0, 3);
                int column = random.Next(0, 3);

                if (IsValidMove(row, column))
                {
                    board[row, column] = Player.Computer;
                    break;
                }
            }
        }

        private bool IsValidMove(int row, int column)
        {
            if (row < 0 || row >= 3 || column < 0 || column >= 3)
            {
                return false;
            }

            return board[row, column] == Player.None;
        }

        private Player CheckWinner()
        {
            // Проверка строк
            for (int row = 0; row < 3; row++)
            {
                if (board[row, 0] != Player.None && board[row, 0] == board[row, 1] && board[row, 0] == board[row, 2])
                {
                    return board[row, 0];
                }
            }

            // Проверка столбцов
            for (int column = 0; column < 3; column++)
            {
                if (board[0, column] != Player.None && board[0, column] == board[1, column] && board[0, column] == board[2, column])
                {
                    return board[0, column];
                }
            }

            // Проверка диагоналей
            if (board[0, 0] != Player.None && board[0, 0] == board[1, 1] && board[0, 0] == board[2, 2])
            {
                return board[0, 0];
            }

            if (board[0, 2] != Player.None && board[0, 2] == board[1, 1] && board[0, 2] == board[2, 0])
            {
                return board[0, 2];
            }

            return Player.None;
        }

        private bool IsBoardFull()
        {
            for (int row = 0; row < 3; row++)
            {
                for (int column = 0; column < 3; column++)
                {
                if (board[row, column] == Player.None)
                {
                    return false;
                }
            }
        }
            return true;
        }

    private void DrawBoard()
    {
        Console.WriteLine("-------------");
        for (int row = 0; row < 3; row++)
        {
            for (int column = 0; column < 3; column++)
            {
                Console.Write("| ");
                Console.Write(board[row, column] == Player.None ? " " : (board[row, column] == Player.Player ? "X" : "O"));
                Console.Write(" ");
            }
            Console.WriteLine("|");
            Console.WriteLine("-------------");
        }
    }
}

class Program
{
    static void Main(string[] args)
    {
        XOGame game = new XOGame();
        game.Start();
        Console.ReadLine();
    }
}
}






//Задание 3 и 4
/*

namespace MorseCodeTranslator
{
    public static class MorseCode
    {
        private static readonly Dictionary<char, string> dictionary = new Dictionary<char, string>()
        {
            {'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."},
            {'E', "."}, {'F', "..-."}, {'G', "--."}, {'H', "...."},
            {'I', ".."}, {'J', ".---"}, {'K', "-.-"}, {'L', ".-.."},
            {'M', "--"}, {'N', "-."}, {'O', "---"}, {'P', ".--."},
            {'Q', "--.-"}, {'R', ".-."}, {'S', "..."}, {'T', "-"},
            {'U', "..-"}, {'V', "...-"}, {'W', ".--"}, {'X', "-..-"},
            {'Y', "-.--"}, {'Z', "--.."}, {'0', "-----"}, {'1', ".----"},
            {'2', "..---"}, {'3', "...--"}, {'4', "....-"}, {'5', "....."},
            {'6', "-...."}, {'7', "--..."}, {'8', "---.."}, {'9', "----."},
            {'.', ".-.-.-"}, {',', "--..--"}, {'?', "..--.."}, {'!', "-.-.--"},
            { 'А',".-" },{'Б',"-..." },{'В',".--" },{'Г',"--." },{'Д',"-.." },
            {'Е',"." },{'Ж',"...-" },{'З',"--.." },{'И',".." },{'Й',".---" },
            {'К',"-.-" },{'Л',".-.." },{'М',"--" },{'Н',"-." },{'О',"---" },
            {'П',".--." },{'Р',".-." },{'С',"..." },{'Т',"-" },{'У',"..-" },
            {'Ф',"..-." },{'Х',"...." },{'Ц',"-.-." },{'Ч',"---." },
            {'Ш',"----" },{'Щ',"--.-" },{'Ъ',"--.--" },{'Ы',"-.--" },
            {'Ь',"-..-" },{'Э',"..-.." },{'Ю',"..--" },{'Я',".-.-" }
        };

        private static readonly Dictionary<string, char> reverseDictionary = new Dictionary<string, char>();

        static MorseCode()
        {
            foreach (KeyValuePair<char, string> pair in dictionary)
            {
                reverseDictionary[pair.Value] = pair.Key;
            }
        }

        public static string Encrypt(string text)
        {
            text = text.ToUpper();
            string morseCode = "";
            foreach (char c in text)
            {
                if (dictionary.ContainsKey(c))
                {
                    morseCode += dictionary[c] + " ";
                }
            }
            return morseCode.Trim();
        }

        public static string Decrypt(string morseCode)
        {
            string[] words = morseCode.Split(' ');
            string text = "";
            foreach (string word in words)
            {
                if (reverseDictionary.ContainsKey(word))
                {
                    text += reverseDictionary[word];
                }
            }
            return text;

        }

        class Program
        {
            static void Main(string[] args)
            {
                do
                {
                    Console.WriteLine("Если вы хотите закодировать текст - нажмите 1");
                    Console.WriteLine("Если вы хотите декодировать текст - нажмите 2");
                    int choice = Convert.ToInt32(Console.ReadLine());
                    switch (choice)
                    {
                        case 1:
                            Console.WriteLine("Введите текст: ");
                            string text = Console.ReadLine();

                            string morseCode = MorseCode.Encrypt(text);
                            Console.WriteLine("Текст в азбуке Морзе: " + morseCode);
                            break;
                        case 2:
                            Console.WriteLine("Введите текст в азбуке Морзе: ");
                            morseCode = Console.ReadLine();

                            string decryptedText = MorseCode.Decrypt(morseCode).ToLower();
                            Console.WriteLine("Расшифрованный текст: " + decryptedText);

                            Console.ReadLine();
                            break;
                        default:
                            Console.WriteLine("Неправильный выбор");
                            break;
                    }



                } while (Console.ReadKey().Key != ConsoleKey.Escape);

            }
        }
    }
}
*/

