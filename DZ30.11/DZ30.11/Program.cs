using System;
using System.Collections.Generic;
using System.IO;

internal class Program
{
    private static void Main(string[] args)
    {
        do
        {
            string path = "@/Users/sergey/GitHub/HomeWork/DZ30.11/DZ30.11/TextFile.txt";
            Dictionary<string, int> wordCount = new Dictionary<string, int>();
            try
            {
                using (StreamReader sr = new StreamReader(path))
                {
                    string line;
                    while ((line = sr.ReadLine()) != null)
                    {
                        string[] words = line.Split(' ');
                        foreach (string e in words)
                        {
                            string cleanedWord = e.Trim
                                (',', '.', '!', '?', ':', ';', '"', '\'', '(', ')');
                            if (!string.IsNullOrWhiteSpace(cleanedWord))
                            {
                                if (wordCount.ContainsKey(cleanedWord))
                                {
                                    wordCount[cleanedWord]++;
                                }
                                else
                                {
                                    wordCount.Add(cleanedWord, 1);
                                }
                            }
                        }
                    }
                }
                Console.WriteLine("Слово: Кол-во:");
                foreach (var e in wordCount)
                {
                    Console.WriteLine($"{e} : {e.Key}: {e.Value}");
                }
            }

            catch (Exception ex)
            {
                Console.WriteLine($"error!!! {ex.Message}");
            }

        } while (Console.ReadKey().Key != ConsoleKey.Escape);
    }
}