using System;

public class RandomNumber
{
    public static main(string[] args)
    {
        // If you are going to create more than one random number, you should keep the Random instance and reuse it. 
        // If you create new instances too close in time, they will produce the same series of random numbers as the 
        // random generator is seeded from the system clock.
        Random rnd = new Random();
        int month = rnd.Next(1, 13); // creates a number between 1 and 12
        int dice = rnd.Next(1, 7);   // creates a number between 1 and 6
        int card = rnd.Next(52);     // creates a number between 0 and 51

        Console.WriteLine($"Random Number: {month}{dice}{card}");
        Console.ReadLine();
    }
}