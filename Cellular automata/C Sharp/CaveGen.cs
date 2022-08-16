using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AdvConGame
{
    class CaveGen
    {
        Random r;
        int seed;
        public bool[,] map;
        int width, height;

        public CaveGen(int width, int height, int seed){
            this.width = width;
            this.height = height;
            this.seed = seed;
            this.map = new bool[width, height];
            r = new Random(seed); 
        }

        public void InitMap()
        {
            RandomizeMap();
            for (int i = 0; i < 5; i++)
                SmoothMap();
        }

        void RandomizeMap()
        {
            for (int x = 0; x < width; x++)
                for (int y = 0; y < height; y++)
                    if (x == 0 || x == width - 1 || y == 0 || y == height - 1)
                        map[x, y] = true;
                    else
                        map[x, y] = r.Next(0, 100) > 43;
        }

        void SmoothMap()
        {
            for (int x = 0; x < width;x++)
                for (int y = 0;y< height;y++)
                {
                    int wallCount = GetWallsOn(x,y);
                    if (wallCount > 4)
                        map[x, y] = true;
                    else if(wallCount < 4)
                        map[x, y] = false;
                }
        }

        int GetWallsOn(int Cx , int Cy)
        {
            int wallCount = 0;
            for (int x = Cx - 1; x <= Cx + 1; x++)
                for (int y = Cy - 1; y <= Cy + 1; y++)
                    if (x >= 0 && x < width && y >= 0 && y < height)
                    {
                        if (Cx != x || Cy != y)
                            if (map[x, y])
                                wallCount++;
                    }
                    else wallCount++;
            return wallCount;
        }
    }
}
