using System;
using System.IO;

class Program
{
    static void Main()
    {
        Console.WriteLine("Введите нзвание файла для копирования");
        string sourceFilePath = Console.ReadLine();
        Console.WriteLine("Введите название нового файла");
        string destinationFilePath = Console.ReadLine();
        CopyFile(sourceFilePath, destinationFilePath);

        Console.WriteLine("Файл скопирован");
    }

    static void CopyFile(string sourcePath, string destinationPath)
    {
        using (FileStream source = new FileStream(sourcePath, FileMode.Open))
        {
            using (FileStream destination = new FileStream(destinationPath, FileMode.Create))
            {
                byte[] buffer = new byte[4086];

                int bytesRead;
                while ((bytesRead = source.Read(buffer, 0, buffer.Length)) > 0)
                {
                    destination.Write(buffer, 0, bytesRead);
                }
            }
        }
    }
}

