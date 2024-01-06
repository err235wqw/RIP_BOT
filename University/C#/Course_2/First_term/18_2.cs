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
//17-2-7
using System;
using System.Collections.Generic;
using System.Collections;
using System.IO;
using System.Diagnostics;
using System.Data;
using System.Linq;
using System.Runtime.InteropServices;
using System.Runtime.Intrinsics.X86;
using System.Diagnostics.Metrics;
using System.Reflection;
using System.Net.Http.Headers;
using System.ComponentModel.DataAnnotations;


class TwoDimensionalArray
{
    private double[][] doubelArray;
    private int quantitiOfStrings, quantitiOfElements;
    public TwoDimensionalArray()
    {
        this.doubelArray = new double[0][];
        this.quantitiOfStrings = 0;
        this.quantitiOfElements = 0;
    }
    public TwoDimensionalArray(double[][] inputArray)
    {
        this.quantitiOfStrings = inputArray.Length;
        this.quantitiOfElements = 0;
        double[][] temp = new double[inputArray.Length][];
        for (int i = 0; i < temp.Length; i++)
        {
            double[] temp2 = new double[inputArray[i].Length];
            inputArray[i].CopyTo(temp2, 0);
            temp[i] = temp2;
            this.quantitiOfElements += temp2.Length;
        }
        this.doubelArray = temp;
    }
    public TwoDimensionalArray(TwoDimensionalArray x)
    {
        this.doubelArray = new double[x.quantitiOfStrings][];
        for (int i = 0; i < x.quantitiOfStrings; i++)
        {
            double[] temp = new double[x.quantitiOfStrings];
            x.doubelArray[i].CopyTo(temp, 0);
            this.doubelArray[i] = temp;
        }
        this.quantitiOfElements = (int)x.quantitiOfElements;
        this.quantitiOfStrings = (int)x.quantitiOfStrings;
    }

    public static TwoDimensionalArray EnteringElements(StreamReader Cin)
    {
        int n = Convert.ToInt32(Cin.ReadLine());
        string[] temp;
        double[][] tempDoubleArray = new double[n][];
        int counterOfStrings = n;
        while (counterOfStrings > 0)
        {
            temp = Cin.ReadLine().Split(new char[] { ' ', '\n', '\t' }, StringSplitOptions.RemoveEmptyEntries);
            counterOfStrings--;
            double[] tempArray = new double[temp.Length];
            for (int i = 0; i < temp.Length; i++)
            {
                tempArray[i] = Convert.ToDouble(temp[i]);
            }
            tempDoubleArray[n - counterOfStrings - 1] = tempArray;
        }
        return new TwoDimensionalArray(tempDoubleArray);
    }

    public override string ToString()
    {
        string outString = "";
        for (int i = 0; i < this.quantitiOfStrings; i++)
        {
            for (int j = 0; j < this.doubelArray[i].Length; j++)
            {
                outString += this.doubelArray[i][j].ToString() + " ";
            }
            outString += '\n';
        }
        return outString;
    }

    public static TwoDimensionalArray operator --(TwoDimensionalArray x)
    {
        TwoDimensionalArray temp = new TwoDimensionalArray(x);
        for (int i = 0; i < x.quantitiOfStrings; i++)
        {
            double[] tempArray = new double[temp.doubelArray[i].Length];
            for (int j = 0; j < temp.doubelArray[i].Length; j++)
            {
                tempArray[j] = -1 + temp.doubelArray[i][j];
            }
            temp.doubelArray[i] = tempArray;
        }
        return temp;
    }
    public static TwoDimensionalArray operator ++(TwoDimensionalArray x)
    {
        TwoDimensionalArray temp = new TwoDimensionalArray(x);
        for (int i = 0; i < x.quantitiOfStrings; i++)
        {
            double[] tempArray = new double[x.doubelArray[i].Length];
            for (int j = 0; j < x.doubelArray[i].Length; j++)
            {
                tempArray[j] = 1 + x.doubelArray[i][j];
            }
            temp.doubelArray[i] = tempArray;
        }
        return temp;
    }

    public static bool operator true(TwoDimensionalArray x)
    {
        for(int i = 0; i < x.quantitiOfStrings; i++)
        {
            for(int j = 1;j < x.doubelArray[i].Length; j++)
            {
                if (x[i, j - 1] > x[i, j])
                {
                    return false;
                }
            }
        }
        return true;
    }
    public static bool operator false(TwoDimensionalArray x)
    {
        for (int i = 0; i < x.quantitiOfStrings; i++)
        {
            for (int j = 1; j < x.doubelArray[i].Length; j++)
            {
                if (x[i, j - 1] > x[i, j])
                {
                    return false;
                }
            }
        }
        return true;
    }

    public static implicit operator double[][](TwoDimensionalArray x)
    {
        double[][] temp = new double[x.quantitiOfStrings][];
        for(int i = 0;i < x.quantitiOfStrings; i++)
        {
            double[] tempst = new double[x.doubelArray[i].Length];
            x.doubelArray[i].CopyTo(tempst, 0);
            temp[i] = tempst;
        }
        return temp;
    }

    public static implicit operator TwoDimensionalArray(double[][] x)
    {
        TwoDimensionalArray temp = new TwoDimensionalArray(x);
        return temp;
    }

    public void StringReverseSort()//+
    {
        for (int i = 0; i < this.quantitiOfStrings; i++)
        {
            Array.Sort(this.doubelArray[i], (x, y) => y.CompareTo(x));
        }
    }

    public int QUANTITIOFELEMENTS

    {
        get
        {
            return this.quantitiOfElements;
        }
    }
    public int PRIBAVKA

    {
        set
        {
            for (int i = 0; i < this.quantitiOfStrings; i++)
            {
                for (int j = 0; j < this.doubelArray[i].Length; i++)
                {
                    this.doubelArray[i][j] += value;
                }
            }
        }
    }

    public double this[int i, int j]
    {
        get
        {
            if (Math.Abs(i) >= this.quantitiOfStrings)
            {
                Console.WriteLine("Wrong Index");
                return 0;
            }
            else
            {
                if (i < 0)//Отрицательный индекс строки
                {
                    i = this.quantitiOfElements + i;
                }
                if (Math.Abs(j) >= this.doubelArray[i].Length)
                {
                    Console.WriteLine("Wrong Index");
                    return 0;
                }
                else
                {
                    if (j < 0)
                    {
                        j = this.doubelArray[i].Length + j;

                    }
                    return this.doubelArray[i][j];
                }
            }
        }
        set
        {
            if (Math.Abs(i) >= this.quantitiOfStrings)
            {
                Console.WriteLine("Wrong Index");
            }
            else
            {
                if (i < 0)//Отрицательный индекс строки
                {
                    i = this.quantitiOfElements + i;
                }
                if (Math.Abs(j) >= this.doubelArray[i].Length)
                {
                    Console.WriteLine("Wrong Index");
                }
                else
                {
                    if (j < 0)
                    {
                        j = this.doubelArray[i].Length + j;

                    }
                    this.doubelArray[i][j] = value;
                }
            }
        }


    }

}
