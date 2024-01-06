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
//15-1-7
using System;
using System.Collections.Generic;
using System.Collections;
using System.IO;
using System.Diagnostics;
using System.Data;
using System.Linq;

class Program
{

    static void Main()
    {
        Int32 k = Convert.ToInt32(Console.ReadLine());
        StreamReader fin = new StreamReader("input.txt");
        List<int> num = new List<int>();
        while (!fin.EndOfStream)
        {
            string[] temp = fin.ReadLine().Split(new char[] { ' ', '\n', '\t' }, StringSplitOptions.RemoveEmptyEntries);
            for (int i = 0; i < temp.Length; i++)
            {
                num.Add(Convert.ToInt32(temp[i]));
            }
        }
        fin.Close();
        var nums =
            from n in num
            where n < k
            select (n>0) ? n*2:n / 2;
        StreamWriter fout = new StreamWriter("output.txt");
        foreach (int n in nums)
        {
            fout.WriteLine("{0}", n);
        }
        fout.Close();
    }
}
