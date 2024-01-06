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
//15-2-7
using System;
using System.Collections.Generic;
using System.Collections;
using System.IO;
using System.Diagnostics;
using System.Data;
using System.Linq;
using System.Runtime.InteropServices;

class Program
{
    struct Pass : IComparable<Pass>
    {
        public string Surname, Name, Second_name;
        int num;
        public float weight;
        public Pass(string Surname, string Name, string Second_name, int num, int weight)
        {
            this.Surname = Surname;
            this.Name = Name;
            this.Second_name = Second_name;
            this.num = num;
            this.weight = weight;
        }
        public string ToString()
        {
            string s = this.Surname+' '+this.Name+' '+this.Second_name+' '+this.num+' '+this.weight;
            return s;
        }
        public int CompareTo(Pass other)
        {
            string temp1 = this.Surname+this.Name+this.Second_name;
            string temp2 = other.Surname + other.Name + other.Second_name;
            int cnt = 0;
            while(cnt < Math.Min(temp1.Length,temp2.Length) && temp1[cnt] == temp2[cnt]) 
            {
                cnt++;
            }
            if(cnt == Math.Min(temp1.Length, temp2.Length))
            {
                if (temp1.Length < temp2.Length)
                {
                    return -1;
                }
                else
                {
                    if (temp1.Length == temp2.Length) 
                    {
                        return 0;
                    
                    }
                    else
                    {
                        return 1;
                    }

                }
            }
            else
            {
                if (temp1[cnt] < temp2[cnt])
                {
                    return -1;
                }
                else
                {
                    return 1;
                }
            }
        }
    }


    static void Main()
    {
        Double k = Convert.ToDouble(Console.ReadLine());
        StreamReader fin = new StreamReader("input.txt");
        List<Pass> Pas = new List <Pass> ();
        while(!fin.EndOfStream)
        {
            string[] temp = fin.ReadLine().Split(new char[] { ' ', '\n', '\t' }, StringSplitOptions.RemoveEmptyEntries);
            Pass temp1 = new Pass(temp[0], temp[1], temp[2], Convert.ToInt32(temp[3]), Convert.ToInt32(temp[4]));
            Pas.Add(temp1);
        }
        fin.Close();
        var passengers =
            from n in Pas
            where n.weight > k
            orderby n
            select n;
        StreamWriter fout = new StreamWriter("output.txt");
        foreach(Pass n in passengers)
        {
            fout.WriteLine(n.ToString());
        }
        fout.Close();
    }
}
