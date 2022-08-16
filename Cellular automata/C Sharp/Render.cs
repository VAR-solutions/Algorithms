using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AdvConGame
{
    class Render
    {
        bool[,] lastFrame;
        public Render()
        {
            lastFrame = new bool[Console.WindowWidth,Console.WindowHeight];
        }

        public void PrintFirstMap(bool[,] map, int cX, int cY)
        {
            for (int x = 0; x < Console.WindowWidth; x++)
                for (int y = 0; y < Console.WindowHeight; y++)
                {
                    Console.SetCursorPosition(x, y);
                    Console.BackgroundColor = map[x + cX, y + cY] ? ConsoleColor.Black : ConsoleColor.White;
                    lastFrame[x, y] = map[x+cX, y+cY];
                    Console.Write(" ");
                }
        }

        public void PrintMap(bool[,] map,int cX, int cY)
        {
            for (int x = 0; x < Console.WindowWidth; x++)
                for (int y = 0; y < Console.WindowHeight; y++)
                {
                    if (lastFrame[x,y] != map[x+cX,y+cY]) {
                        Console.SetCursorPosition(x, y);
                        Console.BackgroundColor = map[x + cX, y + cY] ? ConsoleColor.Black : ConsoleColor.White;
                        Console.Write(" ");
                        lastFrame[x, y] = map[x+cX, y+cY];
                    }
                }
        }
    }
}
