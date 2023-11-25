using System;

// Абстрактный класс "автомобиль"
public abstract class Car
{
    public string Name { get; set; }
    public int Speed { get; set; }

    public Car(string name, int speed)
    {
        Name = name;
        Speed = speed;
    }

    public abstract void StartRace();
}

// Класс гонщика с конкретными реализациями
public class RacingCar : Car
{
    public event EventHandler RaceFinished;

    public RacingCar(string name, int speed) : base(name, speed) { }

    public override void StartRace()
    {
        Console.WriteLine($"The racing car {Name} has started the race.");
        Random rnd = new Random();
        while (true)
        {
            Speed = rnd.Next(50, 150);
            if (Speed >= 100)
            {
                RaceFinished?.Invoke(this, EventArgs.Empty);
                break;
            }
            Console.WriteLine($"The racing car {Name} is at position {Speed}.");
        }
    }
}

// Класс игры
class RacingGame
{
    public delegate void StartRaceDelegate();
    public event EventHandler<string> WinnerDeclared;

    public void Start()
    {
        RacingCar car1 = new RacingCar("Porshe", 0);
        RacingCar car2 = new RacingCar("Ferrari", 0);

        car1.RaceFinished += Car_RaceFinished;
        car2.RaceFinished += Car_RaceFinished;

        StartRaceDelegate startRaceDelegate = car1.StartRace;
        startRaceDelegate += car2.StartRace;

        startRaceDelegate.Invoke();
    }

    private void Car_RaceFinished(object sender, EventArgs e)
    {
        RacingCar car = sender as RacingCar;
        WinnerDeclared?.Invoke(this, $"{car.Name} has won the race!");
    }
}

class Program
{
    static void Main()
    {
        RacingGame game = new RacingGame();
        game.WinnerDeclared += Game_WinnerDeclared;
        game.Start();
    }

    private static void Game_WinnerDeclared(object sender, string e)
    {
        Console.WriteLine(e);
    }
}
