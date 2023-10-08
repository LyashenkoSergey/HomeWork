/* Задание 1
void draw(int length, char symbol)
{
    for (int i = 0; i < length; i++)
    {
        for(int j = 0; j < length; j++)
        {
            if (i > 0 && i < length-1)
            {
                if (j == 0 || j == length - 1)
                {
                    Console.Write(symbol);
                }
                else
                {
                    Console.Write(' ');
                }
            }
            else
            {
                Console.Write(symbol);
            }
        }
        Console.WriteLine();
    }
}

do
{
    Console.WriteLine("Введите длину стороны квадрата");
    int length = Convert.ToInt32(Console.ReadLine());
    Console.WriteLine("Введите символ");
    char symbol = Convert.ToChar(Console.ReadLine());
    draw(length, symbol);
} while (Console.ReadKey().Key != ConsoleKey.Escape) ;


//Задание 2
bool palindrom(int data)
{
    bool flag = true;
    int size = Convert.ToString(data).Length;
    string buf = Convert.ToString(data);
    for (int i = 0; i < size/2; i++)
    {
        for (int j = size - 1-i; j > size / 2; j--)
        {
            if (buf[i] != buf[j])
            {
                flag = false;
                break;
            }
        }
    }
    return flag;
}


do
{
    Console.WriteLine("Введите число");
    int data = Convert.ToInt32(Console.ReadLine());
    Console.WriteLine(palindrom(data));
} while (Console.ReadKey().Key != ConsoleKey.Escape);


//Задание 3
using System;

void fillArray(int[] array)
{
    Random random = new Random();
    for (int i=0; i< array.Length;i++)
    {
        array[i] = random.Next(100);
        
    }
}
void showArray(int[] array)
{
    for (int i = 0; i < array.Length; i++)
    { 
        Console.Write(array[i] + " ; ");
    }
    Console.WriteLine();
}

int[] filterArray(int[] array, int[] filter_array)
{
    int size = 0;
    for (int i = 0; i < array.Length; i++)
    {
        for (int j = 0; j < filter_array.Length; j++)
        {
            if (array[i] == filter_array[j])
            {
                size++;
            }
        }
    }
    int[] buf = new int[array.Length-size];
    size = 0;
    bool flag = true;
    for (int i = 0; i < array.Length; i++)
    {
        flag = true;
        for (int j = 0; j < filter_array.Length; j++)
        {
            if (array[i] == filter_array[j])
            {
                flag = false;          
            }
        }
        if (flag)
            buf[size++] = array[i];
    }
    return buf;
}


do
{
    Console.WriteLine("Введите кол-во элементов в массиве");
    int size = Convert.ToInt32(Console.ReadLine());
    int[] array = new int[size];
    fillArray(array);
    Console.WriteLine("Изначальный массив:");
    showArray(array);
    Console.WriteLine("Введите кол-во элементов в массиве фильтрации");
    int filter_size = Convert.ToInt32(Console.ReadLine());
    Console.WriteLine("Введите элементы фильтрации");
    int[] filter_array = new int[filter_size];
    for(int i = 0; i < filter_size; i++)
    {
        filter_array[i]=Convert.ToInt32(Console.ReadLine());
    }
    int[] buf = filterArray(array, filter_array);
    Console.WriteLine("Массив после фильтрации:");
    showArray(buf);
} while (Console.ReadKey().Key != ConsoleKey.Escape);

// Задание 4

class WebSite
{
    string Name="";
    string Path="";
    string Descriptions="";
    string Ip="";

    public void setName(string name)
    {
        Name = name;
    }
    public string getName()
    {
        return Name;
    }
    public void setPath(string path)
    {
        Path = path;
    }
    public string getPath()
    {
        return Path;
    }
    public void setDescriptions(string descriptions)
    {
        Descriptions = descriptions;
    }
    public string getDescriptions()
    {
        return Descriptions;
    }
    public void setIp(string ip)
    {
        Ip = ip;
    }
    public string getIp()
    {
        return Ip;
    }
    WebSite(string name, string path, string descriptions, string ip)
    {
        Name = name;
        Path = path;
        Descriptions = descriptions;
        Ip = ip;
    }

}


// Задание 5

class Journal
{
    string Name = "";
    DateOnly Date;
    string Descriptions = "";
    string Phone = "";
    string Mail = "";


    public void setName(string name)
    {
        Name = name;
    }
    public string getName()
    {
        return Name;
    }
    public void setData(DateOnly date)
    {
        Date = date;
    }
    public DateOnly GetDate()
    {
        return Date;
    }
    public void setDescriptions(string descriptions)
    {
        Descriptions = descriptions;
    }
    public string getDescriptions()
    {
        return Descriptions;
    }
    public void setPhone(string phone)
    {
        Phone = phone;
    }
    public string getPhone()
    {
        return Phone;
    }
    public void setMail(string mail)
    {
        Mail = mail;
    }
    public string getMail()
    {
        return Mail;
    }
    Journal(string name, DateOnly date, string descriptions,
        string phone, string mail)
    {
        Name = name;
        Date = date;
        Descriptions = descriptions;
        Phone = phone;
        Mail = mail;
    }
};
*/
// Задание 6

class Shop
{
    string Name;
    string Address;
    string Profile;
    string Phone;
    string Mail;

    public void setName(string name)
    {
        Name = name;
    }
    public string getName()
    {
        return Name;
    }
    public void setAddress(string address)
    {
        Address = address;
    }
    public string getAddress()
    {
        return Address;
    }
    public void setProfile(string profile)
    {
        Profile = profile;
    }
    public string getProfile()
    {
        return Profile;
    }
    public void setPhone(string phone)
    {
        Phone = phone;
    }
    public string getPhone()
    {
        return Phone;
    }
    public void setMail(string mail)
    {
        Mail = mail;
    }
    public string getMail()
    {
        return Mail;
    }
    Shop(string name, string address, string profile,
    string phone, string mail){
        Name = name;
        Address = address;
        Profile = profile;
        Phone = phone;
        Mail = mail;
    }

};



