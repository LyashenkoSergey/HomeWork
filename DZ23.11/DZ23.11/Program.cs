using System;
using System.Collections.Generic;
using System.Linq;

public class Karta
{
    public string Suit { get; set; }
    public string Rank { get; set; }

    public Karta(string suit, string rank)
    {
        Suit = suit;
        Rank = rank;
    }
}

public class Player
{
    public List<Karta> Cards { get; set; }

    public void ShowCards()
    {
        foreach (var card in Cards)
        {
            Console.WriteLine($"{card.Rank} of {card.Suit}");
        }
    }
}

public class Game
{
    public List<Player> Players { get; set; }
    public List<Karta> Deck { get; set; }

    public Game()
    {
        Players = new List<Player>();
        Deck = new List<Karta>();
        string[] suits = { "Hearts", "Diamonds", "Clubs", "Spades" };
        string[] ranks = { "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace" };

        foreach (var suit in suits)
        {
            foreach (var rank in ranks)
            {
                Deck.Add(new Karta(suit, rank));
            }
        }
    }

    public void Shuffle()
    {
        Random rnd = new Random();
        Deck = Deck.OrderBy(c => rnd.Next()).ToList();
    }

    public void DealCards()
    {
        int numPlayers = Players.Count;
        int numCardsPerPlayer = Deck.Count / numPlayers;

        for (int i = 0; i < numPlayers; i++)
        {
            Players[i].Cards = Deck.GetRange(i * numCardsPerPlayer, numCardsPerPlayer);
        }
    }

    public void PlayGame()
    {
        while (Players.All(p => p.Cards.Count > 0))
        {
            List<Karta> roundCards = new List<Karta>();
            foreach (var player in Players)
            {
                Karta card = player.Cards[0];
                roundCards.Add(card);
                player.Cards.RemoveAt(0);
                Console.WriteLine($"{player} plays {card.Rank} of {card.Suit}");
            }
            Karta winningCard = roundCards.OrderByDescending(c => c.Rank).First();
            Player winningPlayer = Players.First(p => p.Cards.Contains(winningCard));
            Console.WriteLine($"{winningPlayer} wins the round");
            winningPlayer.Cards.AddRange(roundCards);
        }
        Player gameWinner = Players.OrderByDescending(p => p.Cards.Count).First();
        Console.WriteLine($"{gameWinner} wins the game!");
    }
}

public class Program
{
    public static void Main()
    {
        Game game = new Game();
        Player player1 = new Player();
        Player player2 = new Player();
        game.Players.Add(player1);
        game.Players.Add(player2);
        game.Shuffle();
        game.DealCards();
        game.PlayGame();
    }
}