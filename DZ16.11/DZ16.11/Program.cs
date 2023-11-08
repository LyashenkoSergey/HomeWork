namespace DZ16._11;

class Program
{
    static void Main(string[] args)
    {
        //Задание 1
        /*
                do
                {
                    Money money = new Money(10, 50);
                    money.GetAmount();

                    Product product = new Product("Apple", 5, 99);
                    product.GetPrice().GetAmount();

                    product.DecreasePrice(200);
                    product.GetPrice().GetAmount();
                } while (Console.ReadKey().Key != ConsoleKey.Escape);
        */

        //Задание 2
        /*
        do
        {
            Device Device = new Device("Устройство", "Описание устройства");
            Device.Sound();
            Device.Show();
            Device.Desc();

            Kettle Kettle = new Kettle("Чайник", "Описание чайника");
            Kettle.Sound();
            Kettle.Show();
            Kettle.Desc();

            Microwave Microwave = new Microwave("Микроволновка", "Описание микроволновки");
            Microwave.Sound();
            Microwave.Show();
            Microwave.Desc();

            Avto Avto = new Avto("Автомобиль", "Описание автомобиля");
            Avto.Sound();
            Avto.Show();
            Avto.Desc();

            Ship ship = new Ship("Пароход", "Описание парохода");
            ship.Sound();
            ship.Show();
            ship.Desc();
        } while (Console.ReadKey().Key != ConsoleKey.Escape);
        */

        //Задание 3
        /*
        do
        {
            Violin violin = new Violin("Скрипка", "Скрипка - струнный смычковый музыкальный инструмент", "Скрипка возникла в XVI веке");
            violin.Show();
            violin.Desc();
            violin.History();
            violin.Sound();

            Trombone trombone = new Trombone("Тромбон", "Тромбон - медный духовой музыкальный инструмент", "Тромбон возник в XV веке");
            trombone.Show();
            trombone.Desc();
            trombone.History();
            trombone.Sound();

            Ukulele ukulele = new Ukulele("Укулеле", "Укулеле - струнный щипковый музыкальный инструмент", "Укулеле возникло в XIX веке");
            ukulele.Show();
            ukulele.Desc();
            ukulele.History();
            ukulele.Sound();

            Cello cello = new Cello("Виолончель", "Виолончель - струнный смычковый музыкальный инструмент", "Виолончель возникла в XVI веке");
            cello.Show();
            cello.Desc();
            cello.History();
            cello.Sound();

        } while (Console.ReadKey().Key != ConsoleKey.Escape);
        */

        //Задание 4

        do
        {

            President president = new President("Walter White");
            president.Print();

            Console.WriteLine();

            Security security = new Security("Mitchael Jacson");
            security.Print();

            Console.WriteLine();

            Manager manager = new Manager("Pall Shark");
            manager.Print();

            Console.WriteLine();

            Engineer engineer = new Engineer("Jacky Racher");
            engineer.Print();

            Console.WriteLine();
        } while (Console.ReadKey().Key != ConsoleKey.Escape);
    }
}

// Задание 1
/*
class Money
{
private int dollars;
private int cents;

public Money(int dollars, int cents)
{
this.dollars = dollars;
this.cents = cents;
}

public void GetAmount()
{
Console.WriteLine($"{dollars}.{cents}");
}

public int GetDollars() => dollars;
public int GetCents() => cents;

public void SetAmount(int dollars, int cents)
{
this.dollars = dollars;
this.cents = cents;
}
}

class Product
{
private string name;
private Money price;

public Product(string name, int dollars, int cents)
{
this.name = name;
this.price = new Money(dollars, cents);
}

public void DecreasePrice(int amount)
{
int totalCents = price.GetCents() - amount;
if (totalCents < 0)
{
    int dollarsToRemove = (-totalCents) / 100 + 1;
    int centsToAdd = dollarsToRemove * 100 + totalCents;
    price.SetAmount(price.GetDollars() - dollarsToRemove, centsToAdd);
}
else
{
    price.SetAmount(price.GetDollars(), totalCents);
}
}

public string GetName()
{
return name;
}

public Money GetPrice()
{
return price;
}
}
*/


// Задание 2
/*
class Device
{
protected string Name;
protected string Characteristic;

public Device(string name, string characteristic)
{
Name = name;
Characteristic = characteristic;
}

public virtual void Sound()
{
Console.WriteLine("Выпускает звук");
}

public void Show()
{
Console.WriteLine("Название устройства: " + Name);
}

public void Desc()
{
Console.WriteLine("Описание устройства: " + Characteristic);
}
}

class Kettle : Device
{
public Kettle(string name, string characteristic) : base(name, characteristic)
{
}

public override void Sound()
{
Console.WriteLine("Чайник издает звук свиста");
}
}

class Microwave : Device
{
public Microwave(string name, string characteristic) : base(name, characteristic)
{
}

public override void Sound()
{
Console.WriteLine("Микроволновка издает звук гудения");
}
}

class Avto : Device
{
public Avto(string name, string characteristic) : base(name, characteristic)
{
}

public override void Sound()
{
Console.WriteLine("Автомобиль издает звук двигателя");
}
}

class Ship : Device
{
public Ship(string name, string characteristic) : base(name, characteristic)
{
}

public override void Sound()
{
Console.WriteLine("Пароход издает звук паровых сирен");
}
}
*/

// Задание 3
/*
public class MusicalInstrument
{
    public string Name { get; set; }
    public string Description { get; set; }
    public string History { get; set; }

    public MusicalInstrument(string name, string description, string history)
    {
        Name = name;
        Description = description;
        History = history;
    }

    public virtual void Sound()
    {
        Console.WriteLine("Инструмент издает звук");
    }

    public void Show()
    {
        Console.WriteLine("Название музыкального инструмента: " + Name);
    }

    public void Desc()
    {
        Console.WriteLine("Описание музыкального инструмента: " + Description);
    }

    public void History()
    {
        Console.WriteLine("История создания музыкального инструмента: " + History);
    }
}

public class Violin : MusicalInstrument
{
    public Violin(string name, string description, string history) : base(name, description, history)
    {
    }

    public override void Sound()
    {
        Console.WriteLine("Скрипка издает звук");
    }
}

public class Trombone : MusicalInstrument
{
    public Trombone(string name, string description, string history) : base(name, description, history)
    {
    }

    public override void Sound()
    {
        Console.WriteLine("Тромбон издает звук");
    }
}

public class Ukulele : MusicalInstrument
{
    public Ukulele(string name, string description, string history) : base(name, description, history)
    {
    }

    public override void Sound()
    {
        Console.WriteLine("Укулеле издает звук");
    }
}

public class Cello : MusicalInstrument
{
    public Cello(string name, string description, string history) : base(name, description, history)
    {
    }

    public override void Sound()
    {
        Console.WriteLine("Виолончель издает звук");
    }
}
*/

//Задание 4

public abstract class Worker
{
    public string Name { get; }
    public string Position { get; }

    public Worker(string name, string position)
    {
        Name = name;
        Position = position;
    }

    public abstract void Print();
}

public class President : Worker
{
    public President(string name) : base(name, "Президент")
    {
    }

    public override void Print()
    {
        Console.WriteLine("Имя: " + Name);
        Console.WriteLine("Должность: " + Position);
        Console.WriteLine("Президент всегда принимает стратегические решения.");
    }
}

public class Security : Worker
{
    public Security(string name) : base(name, "Охранник")
    {
    }

    public override void Print()
    {
        Console.WriteLine("Имя: " + Name);
        Console.WriteLine("Должность: " + Position);
        Console.WriteLine("Охранник обеспечивает безопасность предприятия.");
    }
}

public class Manager : Worker
{
    public Manager(string name) : base(name, "Менеджер")
    {
    }

    public override void Print()
    {
        Console.WriteLine("Имя: " + Name);
        Console.WriteLine("Должность: " + Position);
        Console.WriteLine("Менеджер управляет работой отдела или проекта.");
    }
}

public class Engineer : Worker
{
    public Engineer(string name) : base(name, "Инженер")
    {
    }

    public override void Print()
    {
        Console.WriteLine("Имя: " + Name);
        Console.WriteLine("Должность: " + Position);
        Console.WriteLine("Инженер занимается проектированием и разработкой.");
    }
}


