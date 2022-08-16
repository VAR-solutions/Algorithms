using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace AdvConGame
{
    class Game
    {
        Random r = new Random();
        CaveGen caveGen;
        Render render;

        public int seed;
        int width = 1000, height = 30;
        public bool[,] map;

        public Game()
        {
            SetSeed();
        }

        public void start()
        {
            map = new bool[width, height];
            caveGen = new CaveGen(width,height,seed);
            render = new Render();
            caveGen.InitMap();
            map = caveGen.map;
            int x = 0, y = 0;
            render.PrintFirstMap(map, 0, 0);
            while (true)
            {
                render.PrintMap(map,x,y);
                while (Console.KeyAvailable)
                {
                    ConsoleKeyInfo key = Console.ReadKey(true);
                    switch (key.Key)
                    {
                        case ConsoleKey.A:
                            if(x > 0)
                            x--;
                            break;
                        case ConsoleKey.W:
                            if(y > 0)
                            y--;
                            break;
                        case ConsoleKey.S:
                            if(y < height - Console.WindowHeight)
                            y++;
                            break;
                        case ConsoleKey.D:
                            if(x < width -Console.WindowWidth)
                            x++;
                            break;
                    }
                }
            }
        }

        void SetSeed()
        {
            seed = r.Next();
        }
    }
}
