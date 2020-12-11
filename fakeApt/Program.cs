using System;
using System.Threading;

namespace fakeApt
{
    class Program
    {
        public static int installedDirectories;
        public static int archiveSize;
        public static int diskSpace;
        public static int downloadTime;

        static void Main(string[] args)
        {
            Console.Clear();
            Console.ForegroundColor = ConsoleColor.Green;
            Console.Write("ninjacheetah@MintPad-tm");
            Console.ForegroundColor = ConsoleColor.White;
            Console.Write(":");
            Console.ForegroundColor = ConsoleColor.Blue;
            Console.Write("~");
            Console.ForegroundColor = ConsoleColor.White;
            Console.Write("$ sudo apt install ");
            var fakePackage = Console.ReadLine();
            Console.Write("Reading package lists... ");
            Thread.Sleep(500);
            Console.WriteLine("Done");
            Console.WriteLine("Building dependency tree");
            Thread.Sleep(650);
            Console.Write("Reading state information... ");
            Thread.Sleep(650);
            Console.WriteLine("Done");
            Thread.Sleep(750);
            Console.WriteLine("The following NEW packages will be installed:");
            Console.WriteLine("  " + fakePackage);
            Thread.Sleep(750);
            Console.WriteLine("0 upgraded, 1 newly installed, 0 to remove and 0 not upgraded.");
            Thread.Sleep(650);
            var generator = new RandomGenerator();
            archiveSize = generator.RandomNumber(1, 72);
            Console.WriteLine("Need to get " + archiveSize + " mB of archives.");
            Thread.Sleep(150);
            diskSpace = archiveSize + generator.RandomNumber(1, 72);
            Console.WriteLine("After this operation, "+diskSpace+" mB of additional disk space will be used.\nGet:1 http://archive.ubuntu.com/ubuntu focal-updates/universe amd64 "+fakePackage+" amd64 7:4.2.4-1ubuntu0.1 ["+archiveSize+"]");
            downloadTime = generator.RandomNumber(750, 5000);
            Thread.Sleep(downloadTime);
            Console.WriteLine("Fetched "+archiveSize+" mB in "+downloadTime+"ms");
            Thread.Sleep(750);
            Console.WriteLine("Selecting previously unselected package "+fakePackage+".");
            installedDirectories = generator.RandomNumber(10000, 800000);
            Thread.Sleep(750);
            Console.WriteLine("(Reading database ... "+installedDirectories+" files and directories currently installed.)");
            Console.WriteLine("Preparing to unpack .../"+fakePackage+"_7%3a4.2.4-1ubuntu0.1_amd64.deb ...");
            Thread.Sleep(750);
            Console.WriteLine("Unpacking "+fakePackage+" (7:4.2.4-1ubuntu0.1) ...");
            Thread.Sleep(2000);
            Console.WriteLine("Setting up "+fakePackage+" (7:4.2.4-1ubuntu0.1) ...");
            Thread.Sleep(2000);
            Console.WriteLine("Processing triggers for man-db (2.9.1-1) ...\n");
            Thread.Sleep(2000);
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
