using System;
using System.IO;
using System.Configuration;

namespace Logger
{
    public class Loger
    {
        private string logFilePath;
        private string configFilePath;

        public Loger(string logFilePath, string configFilePath)
        {
            this.logFilePath = logFilePath;
            this.configFilePath = configFilePath;
        }

        public void LogMessage(string type, string message)
        {
            string logMessage = $"{DateTime.Now.ToString()} - {type} - {Environment.UserName} - {message}";

            using (StreamWriter writer = new StreamWriter(logFilePath, true))
            {
                writer.WriteLine(logMessage);
            }
        }

        public void LoadConfig()
        {
            string typeMask = ConfigurationManager.AppSettings["TypeMask"];
            string messageMask = ConfigurationManager.AppSettings["MessageMask"];
            Console.WriteLine("Type mask: " + typeMask);
            Console.WriteLine("Message mask: " + messageMask);

        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Loger loger = new Loger("log.txt", "config.ini");
            loger.LogMessage("Error", "An error occurred in the application");
            loger.LogMessage("Information", "User logged in successfully");
            loger.LoadConfig();
        }
    }
}
