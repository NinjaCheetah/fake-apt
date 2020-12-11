using System;
using System.Threading;

namespace fakeApt
{
    class Program
    {
        public static string username = Environment.UserName;
        public static string devicename = Environment.MachineName;
        public static int installedDirectories;
        public static int archiveSize;
        public static int diskSpace;
        public static int downloadTime;
        public static int v1;
        public static int v2;
        public static int v3;
        public static int v4;

        static void Main(string[] args)
        {
            Console.Clear();
            Console.ForegroundColor = ConsoleColor.Green;
            Console.Write(username+"@"+devicename);
            Console.ForegroundColor = ConsoleColor.White;
            Console.Write(":");
            Console.ForegroundColor = ConsoleColor.Blue;
            Console.Write("~");
            Console.ForegroundColor = ConsoleColor.White;
            Console.Write("$ sudo apt install ");
            var fakePackage = Console.ReadLine();
            if(fakePackage=="BSOD") SecretBSOD();
            if(fakePackage=="spam") SecretSpam();
            Console.Write("Reading package lists... ");
            Thread.Sleep(600);
            Console.WriteLine("Done");
            Console.WriteLine("Building dependency tree");
            Thread.Sleep(750);
            Console.Write("Reading state information... ");
            Thread.Sleep(750);
            Console.WriteLine("Done");
            Thread.Sleep(850);
            Console.WriteLine("The following NEW packages will be installed:");
            Console.WriteLine("  " + fakePackage);
            Thread.Sleep(850);
            Console.WriteLine("0 upgraded, 1 newly installed, 0 to remove and 0 not upgraded.");
            Thread.Sleep(750);
            var generator = new RandomGenerator();
            archiveSize = generator.RandomNumber(1, 84);
            Console.WriteLine("Need to get " + archiveSize + " mB of archives.");
            Thread.Sleep(250);
            diskSpace = archiveSize + generator.RandomNumber(1, 84);
            v1 = generator.RandomNumber(0, 25);
            v2 = generator.RandomNumber(0, 50);
            v3 = generator.RandomNumber(0, 9);
            v4 = generator.RandomNumber(0, 9);
            Console.WriteLine("After this operation, "+diskSpace+" mB of additional disk space will be used.\nGet:1 http://archive.ubuntu.com/ubuntu focal-updates/universe amd64 "+fakePackage+" amd64 "+v1+":"+v2+"."+v3+"."+v4+" ["+archiveSize+" mB]");
            downloadTime = generator.RandomNumber(750, 6000);
            Thread.Sleep(downloadTime);
            Console.WriteLine("Fetched "+archiveSize+" mB in "+downloadTime+"ms");
            Thread.Sleep(850);
            Console.WriteLine("Selecting previously unselected package "+fakePackage+".");
            installedDirectories = generator.RandomNumber(10000, 800000);
            Thread.Sleep(850);
            Console.WriteLine("(Reading database ... "+installedDirectories+" files and directories currently installed.)");
            Console.WriteLine("Preparing to unpack .../"+fakePackage+"_"+v1+":"+v2+"."+v3+"."+v4+"-amd64.deb ...");
            Thread.Sleep(750);
            Console.WriteLine("Unpacking "+fakePackage+" ("+v1+":"+v2+"."+v3+"."+v4+") ...");
            Thread.Sleep(2000);
            Console.WriteLine("Setting up "+fakePackage+" ("+v1+":"+v2+"."+v3+"."+v4+") ...");
            Thread.Sleep(2000);
            Console.WriteLine("Processing triggers for man-db (2.9.1-1) ...\n");
            Thread.Sleep(2000);
        }

        public static void SecretBSOD() {
            Thread.Sleep(2500);
            Console.BackgroundColor = ConsoleColor.DarkBlue;
            Console.Clear();
            Console.WriteLine(":(");
            Console.WriteLine("An error has occurred. Press any key to exit apt.");
            Console.ReadKey();
            Console.ResetColor();
            Console.Clear();
            Environment.Exit(0);
        }

        public static void SecretSpam() {
            Thread.Sleep(2500);
            Console.Clear();
            while (true) {
                Console.WriteLine("Ctrl-C");
            }
        }

        public class RandomGenerator  
        {  
            // Create random instance
            private readonly Random _random = new Random();  
  
            // Generates a random number within a range.      
            public int RandomNumber(int min, int max)  
            {  
                return _random.Next(min, max);  
            }  
        }
    }
}
