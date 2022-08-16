using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.InteropServices;

namespace AdvConGame
{
    class Program
    {
        static Game game;

        static void Main(string[] args)
        {
            Console.Title = "Game";
            Console.SetWindowSize(70, 30);
            Console.CursorVisible = false;
            game = new Game();
            game.start();
        }
    }
}
