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
//14-2-7
using System;
using System.IO;

class Program
{
    struct Toy : IComparable<Toy>
    {
        public int price;
        public string name;
        public int from, to;
        public Toy(string name, int price, int from, int to)
        {
            this.name = name;
            this.price = price;
            this.from = from;
            this.to = to;
        }
        public int CompareTo(Toy temp)
        {
            if(this.price<temp.price)
                return -1;
            else if(this.price>temp.price)
                return 1;
            else
                return 0;
        }
    }

    static void Main()
    {
        StreamReader f1 = new StreamReader("input.txt");
        List<Toy> vedo = new List<Toy>();
        int n = Convert.ToInt32(Console.ReadLine());
        int m = Convert.ToInt32(Console.ReadLine());
        while (!f1.EndOfStream)
        {
            string temp_name = f1.ReadLine();
            int temp_price = Convert.ToInt32(f1.ReadLine());
            int temp_from = Convert.ToInt32(f1.ReadLine());
            int temp_to = Convert.ToInt32(f1.ReadLine());


            Toy temp = new Toy(temp_name, temp_price, temp_from, temp_to);
            vedo.Add(temp);
        }
        f1.Close();
        List<Toy> ved = new List<Toy>();
        for (int i = 0; i < vedo.Count; i++)
        {
            if (vedo[i].from >= n && vedo[i].to <= m)
            {
                ved.Add(vedo[i]);
            }
        }
        ved.Sort();
        StreamWriter f2 = new StreamWriter("vedo.txt");
        for (int i = 0; i < ved.Count; i++)
        {
            f2.WriteLine($"{ved[i].name} {ved[i].price} {ved[i].from} {ved[i].to}");
        }

        f2.Close();
    }
}
