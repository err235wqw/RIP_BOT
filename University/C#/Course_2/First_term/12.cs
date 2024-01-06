//                   ___  _____ ______                       
//    ___  _________|__ \|__  // ____/      ______ __      __
//   / _ \/ ___/ ___/_/ / /_ </___ \| | /| / / __ `/ | /| / /
//  /  __/ /  / /  / __/___/ /___/ /| |/ |/ / /_/ /| |/ |/ / 
//  \___/_/  /_/  /____/____/_____/ |__/|__/\__, / |__/|__/  
//                                            /_/            ⠀
//⣿⣿⣿⠟⠛⠛⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⢋⣩⣉⢻
//⣿⣿⣿⠀⣿⣶⣕⣈⠹⠿⠿⠿⠿⠟⠛⣛⢋⣰⠣⣿⣿⠀⣿
//⣿⣿⣿⡀⣿⣿⣿⣧⢻⣿⣶⣷⣿⣿⣿⣿⣿⣿⠿⠶⡝⠀⣿
//⣿⣿⣿⣷⠘⣿⣿⣿⢏⣿⣿⣋⣀⣈⣻⣿⣿⣷⣤⣤⣿⡐⢿
//⣿⣿⣿⣿⣆⢩⣝⣫⣾⣿⣿⣿⣿⡟⠿⠿⠦⠀⠸⠿⣻⣿⡄⢻
//⣿⣿⣿⣿⣿⡄⢻⣿⣿⣿⣿⣿⣿⣿⣿⣶⣶⣾⣿⣿⣿⣿⠇⣼
//⣿⣿⣿⣿⣿⣿⡄⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⣰
//⣿⣿⣿⣿⣿⣿⠇⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢀⣿
//⣿⣿⣿⣿⣿⠏⢰⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢸⣿
//⣿⣿⣿⣿⠟⣰⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⣿
//⣿⣿⣿⠋⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡄⣿
//⣿⣿⠋⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⢸
//⣿⠏⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡯⢸
//14-1-7
using System;
using System.IO;

class Program
{
    struct SPoint
    {
        public int x, y;
        public SPoint(int x, int y)
        {
            this.x = x;
            this.y = y;
        }
        public void Show()
        {
            Console.WriteLine("({0}, {1})", x, y);
        }
        public double Distance(int x2, int y2)
        {
            return Math.Sqrt((x - x2) * (x - x2) + (y - y2) * (y - y2));
        }
    }

    static void Main()
    {
        List<SPoint> points = new List<SPoint>();



        StreamReader f1 = new StreamReader("input24.txt");
        while (!f1.EndOfStream)
        {
            string[] temp = f1.ReadLine().Split(new char[] { ' ', '\n', '\t' }, StringSplitOptions.RemoveEmptyEntries);
            int tempx = Convert.ToInt32(temp[0]), tempy = Convert.ToInt32(temp[1]);
            SPoint tt = new SPoint(tempx, tempy);
            points.Add(tt);
        }
        f1.Close();

        double min = 1e9;
        int n1 = -1, n2 = -1;
        List<Tuple<int, int>> ans = new List<Tuple<int, int>>();
        for (int i = 0; i < points.Count; i++)
        {
            for (int j = i+1; j < points.Count; j++)
            {
                if (i != j && points[i].Distance(points[j].x, points[j].y) < min)
                {
                    ans.Clear();
                    min = points[i].Distance(points[j].x, points[j].y);
                    Tuple<int, int> temp1 = new Tuple<int, int>(i, j);
                    ans.Add(temp1);

                } else if(points[i].Distance(points[j].x, points[j].y) == min)
                {
                    Tuple<int, int> temp1 = new Tuple<int, int>(i, j);
                    ans.Add(temp1);
                }
            }
        }
        StreamWriter f2 = new StreamWriter("cnn.txt");
        for (int i = 0;i < ans.Count;i++)
        {
            f2.WriteLine($"{ans[i].Item1} {ans[i].Item2}");
        }
        f2.Close();
    }
}
