//Задача 1
/*
do
{


    double[] A = new double[5];
    double[,] B = new double[3, 4];
    double max = 0, min = 0, summ = 0, multi = 1, summA = 0, summB=0 ; 
    for (int i = 0; i < 5; i++)
    {
        Console.WriteLine($"Введите {i + 1} число");
        A[i] = Convert.ToDouble(Console.ReadLine());
    }
        max = A[0];
        min = A[0];
    Random random = new Random();
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            B[i, j] = random.Next(100);
        }
    }
    for (int i = 0; i < A.GetLength(0); i++)
    {
        if (max < A[i])
            max = A[i];
        if (min > A[i])
            min = A[i];
        summ += A[i];
        multi *= A[i];
        if (i % 2 == 0)
            summA += A[i];
        Console.Write($"{A[i]};");
    }
    Console.WriteLine();
    for (int i = 0; i < B.GetLength(0); i++)
    {
        for (int j = 0; j < B.GetLength(1); j++)
        {
            if (max < B[i,j])
                max = B[i,j];
            if (min > B[i,j])
                min = B[i,j];
            summ += B[i, j];
            multi *= B[i, j];
            if (j % 2 != 0)
            {
                summB += B[i, j];
            }
            Console.Write($"{B[i, j]};"); 
        }
        Console.WriteLine();
    }
    Console.WriteLine($"Минимальный элемент = {min}");
    Console.WriteLine($"Максимальный элемент = {max}");
    Console.WriteLine($"Сумма всех элементов = {summ}");
    Console.WriteLine($"Произведение всех элементов = {multi}");
    Console.WriteLine($"Сумма всех четных элементов массива А = {summA}");
    Console.WriteLine($"Сумма всех элементов в нечетных столбцах массива B = {summB}");


} while (Console.ReadKey().Key != ConsoleKey.Escape);



//Задача 2

Random randon = new Random();
int[,] array = new int[5, 5];
int max = 0, min = 0, summ = 0;
int[] indexMin = new int[2] {0,0};
int[] indexMax = new int[2] {0,0};
for (int i = 0; i < array.GetLength(0); i++)
{
    for (int j = 0; j < array.GetLength(1); j++)
    {
        array[i, j] = randon.Next(-100, 100);
    }
}
max = array[0, 0];
min = array[0, 0];
for (int i = 0; i < array.GetLength(0); i++)
{
    for (int j = 0; j < array.GetLength(1); j++)
    {
        if (max < array[i, j])
        {
            max = array[i, j];
            indexMax[0] = i;
            indexMax[1] = j;
        }
        if (min > array[i, j])
        {
            min = array[i, j];
            indexMin[0] = i;
            indexMin[1] = j;
        }
    }
}
if (indexMin[0] <= indexMax[0] && indexMin[1] < indexMax[1])
{
    for (int i = indexMin[0]; i < indexMax[0]; i++)
    {
        for (int j = indexMin[1]; j < indexMax[1]; j++)
        {
            summ += array[i, j];
        }

    }
}
else if (indexMin[1] < indexMax[1])
{
    for (int i = indexMin[0]; i < indexMax[0]; i++)
    {
        for (int j = indexMin[1]; j < indexMax[1]; j++)
        {
            summ += array[i, j];
        }

    }
}
else if(indexMin[0] >= indexMax[0] && indexMin[1] > indexMax[1])
{
    for (int i = indexMax[0]; i > indexMin[0]; i--)
    {
        for (int j = indexMax[1]; j > indexMin[1]; j--)
        {
            summ += array[i, j];
        }

    }
}
else
{
    for (int i = indexMax[0]; i > indexMin[0]; i--)
    {
        for (int j = indexMax[1]; j > indexMin[1]; j--)
        {
            summ += array[i, j];
        }

    }
}
Console.WriteLine($"Сумма всех элементов массива, расположенных между" +
    $"минимальным и маквимальным элементами = {summ}");


//Задача 3

using System.Text;


do
{
   
    uint k = 0;
    string s = "";
    string result = "";
    uint shift;
    Console.WriteLine("Введите 1 для шифрования или 2 для дешифрования");
    while ((k != 1) && (k != 2))
    {
        uint.TryParse(Console.ReadLine(), out k);
        if ((k != 1) && (k != 2))
            Console.WriteLine("Ошибка ввода, повторите попытку");
    }
    Console.WriteLine("Введите величину сдвига");
    while (!uint.TryParse(Console.ReadLine(), out shift))
    {
        Console.WriteLine("Ошибка ввода, повторите попытку");
    }
    if (shift > 32)
        shift = shift % 32;
    if (k == 1)
    {
        Console.WriteLine("Введите строку для шифрования");
        s = Console.ReadLine();

        for (int i = 0; i < s.Length; i++)
        {
            if (((int)(s[i]) < 1040) || ((int)(s[i]) > 1103))
                result += s[i];
            if ((Convert.ToInt16(s[i]) >= 1072) && (Convert.ToInt16(s[i]) <= 1103))
            {
                if (Convert.ToInt16(s[i]) + shift > 1103)
                    result += Convert.ToChar(Convert.ToInt16(s[i]) + shift - 32);
                else
                    result += Convert.ToChar(Convert.ToInt16(s[i]) + shift);
            }
            if ((Convert.ToInt16(s[i]) >= 1040) && (Convert.ToInt16(s[i]) <= 1071))
            {
                if (Convert.ToInt16(s[i]) + shift > 1071)
                    result += Convert.ToChar(Convert.ToInt16(s[i]) + shift - 32);
                else
                    result += Convert.ToChar(Convert.ToInt16(s[i]) + shift);
            }
        }
        Console.WriteLine("Строка успешно зашифрована!");
        Console.WriteLine(result);
    }
    if (k == 2)
    {
        Console.WriteLine("Введите зашифрованную строку");
        s = Console.ReadLine();
        for (int i = 0; i < s.Length; i++)
        {
            if (Convert.ToInt16(s[i]) == 32)
                result += ' ';
            if ((Convert.ToInt16(s[i]) >= 1072) && (Convert.ToInt16(s[i]) <= 1103))
            {
                if (Convert.ToInt16(s[i]) - shift < 1072)
                    result += Convert.ToChar(Convert.ToInt16(s[i]) - shift + 32);
                else
                    result += Convert.ToChar(Convert.ToInt16(s[i]) - shift);
            }
            if ((Convert.ToInt16(s[i]) >= 1040) && (Convert.ToInt16(s[i]) <= 1071))
            {
                if (Convert.ToInt16(s[i]) - shift < 1040)
                    result += Convert.ToChar(Convert.ToInt16(s[i]) - shift + 32);
                else
                    result += Convert.ToChar(Convert.ToInt16(s[i]) - shift);
            }
        }
        Console.WriteLine("Строка успешно дешифрована!");
        Console.WriteLine(result);
    }
    Console.WriteLine("Для выхода из программы нажмите Escape");
} while (Console.ReadKey(true).Key != ConsoleKey.Escape);



//Задача 4

using System;


    int[,] fillMatrix(int row, int col)
    {
        Random random = new Random();
        int[,] buf = new int[row, col];
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                buf[i, j] = random.Next(100);
            }
        }
        return buf;
    }
    void showMatrix(int[,] matrix)
    {
        for (int i = 0; i < matrix.GetLength(0); i++)
        {
            for (int j = 0; j < matrix.GetLength(1); j++)
            {
                Console.Write($"{matrix[i, j]}; ");
            }
            Console.WriteLine();
        }
    }

do
{
    Console.WriteLine("Введите кол-во строк в матрице");
    int row = Convert.ToInt32(Console.ReadLine());
    Console.WriteLine("Введите кол-во столбцов в матрице");
    int col = Convert.ToInt32(Console.ReadLine());
    int[,] matrix1 = fillMatrix(row, col);
    uint k = 0;
    Console.WriteLine("Введите " +
        "1 для умножения матрицы на число;" +
        "2 для сложения матриц;" +
        "3 для умножения матриц");
    while ((k != 1) && (k != 2) && (k != 3))
    {
        uint.TryParse(Console.ReadLine(), out k);
        if ((k != 1) && (k != 2) && (k != 3))
            Console.WriteLine("Ошибка ввода, повторите попытку");
    }
    if (k == 1)
    {
        Console.WriteLine("Введите число, на которое вы хотите умножить матрицу");
        int num = Convert.ToInt32(Console.ReadLine());
        int[,] buf = new int[row, col];
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                buf[i, j] = matrix1[i, j] * num;
            }
        }
        Console.WriteLine("Первоначальный массив: ");
        showMatrix(matrix1);
        Console.WriteLine($"Массив после умножения на число {num} ");
        showMatrix(buf);
    }
    else if (k == 2) {
        int[,] matrix2 = fillMatrix(row, col);
        int[,] buf = new int[row, col];
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                buf[i, j] = matrix1[i, j] + matrix2[i,j];
            }
        }
        Console.WriteLine("Первоначальный первый массив: ");
        showMatrix(matrix1);
        Console.WriteLine("Первоначальный второй массив: ");
        showMatrix(matrix2);
        Console.WriteLine($"Массив после сложения первого и второго массивов");
        showMatrix(buf);
    }
    else
    {
        int[,] matrix2 = fillMatrix(row, col);
        int[,] buf = new int[row, col];
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                buf[i, j] = matrix1[i, j] * matrix2[i, j];
            }
        }
        Console.WriteLine("Первоначальный первый массив: ");
        showMatrix(matrix1);
        Console.WriteLine("Первоначальный второй массив: ");
        showMatrix(matrix2);
        Console.WriteLine($"Массив после умножения первого и второго массивов");
        showMatrix(buf);
    }

} while (Console.ReadKey(true).Key != ConsoleKey.Escape) ;



//Задача 5

do
{
    Console.WriteLine("Введите арифметическое выражение");
    string str = Console.ReadLine();
    int counter = 0;
    double result = 0f;

    for (int i = 0; i < str.Length; i++)
    {
        if (str[i] == '+')
        {
            counter=1;
            break;
        }
    }
    if (counter == 1)
    {
        string[] data = str.Split('+');
        double[] num = new double[data.Length];
        
        for (int i = 0; i < num.Length; i++)
        {
            num[i] = Convert.ToDouble(data[i]);
            result += num[i];
        }
    }
    else
    {
        string[] data = str.Split('-');
        double[] num = new double[data.Length];

        for (int i = 0; i < num.Length; i++)
        {
            num[i] = Convert.ToDouble(data[i]);
            
        }
        result = num[0];
        for (int i = 1; i < num.Length; i++)
        {
            result -= num[i];
        }
    }
    Console.WriteLine(result);


} while (Console.ReadKey(true).Key != ConsoleKey.Escape) ;



//Задача 6

do
{
    Console.WriteLine("Введите текст");
    string str = Console.ReadLine();
    string[] buf = str.Split('.');
    for (int i = 0; i < buf.Length; i++)
    {
        if (buf[i].Length > 1)
        {
            buf[i] = buf[i].ToLower();
            buf[i] = buf[i].Substring(i, 1).ToUpper() + buf[i].Substring(1, buf[i].Length - 1)+".";
            ;
        }
        else buf[i] = buf[i].ToUpper();

    }
    for (int i = 0; i < buf.Length; i++)
    {
        Console.Write(buf[i]);
    }


} while (Console.ReadKey(true).Key != ConsoleKey.Escape) ;

*/

//Задача 7

do
{
    Console.WriteLine("Введите текст");
    string text = Console.ReadLine();
    string[] buf = text.Split(' ',',','.',';');
    Console.WriteLine("Введите недопустимое слово");
    string word = Console.ReadLine();
    string symbols = "";
    for(int i = 0; i < word.Length; i++)
    {
        symbols += '*';
    }
    int counter = 0;
    for (int i = 0; i < buf.Length; i++)
    {
        if (buf[i] == word)
        {
            counter++;
            buf[i] = symbols;
                
        }
    }
    text = "";
    for (int i = 0; i < buf.Length; i++)
    {
        text += buf[i] + " ";
    }
    Console.WriteLine(text);


    } while (Console.ReadKey(true).Key != ConsoleKey.Escape);


