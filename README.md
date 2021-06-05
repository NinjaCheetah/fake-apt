# fake-apt
A fun little program I originally made in .NET 5, and then rewrote in C. It just goes through a fake `apt install` process. Simply load it up (instructions below), enter a package name after the pre-typed `sudo apt install` prompt, and watch it go! Fool your friends... maybe.
## Running the thing
First, go to the Actions tab, then find the latest (successful) run and download either `fake-apt-linux.zip` or `fake-apt-macX86.zip`, depending on your operating system. Extract that to a folder you can easily access.
NOTE: The new C version will only run on macOS and Linux.
### macOS
1. Open the terminal, and navigate to the folder that has the extracted program in it.
2. Run `./fake-aptX86`
3. Enjoy!
### Linux
1. Open the terminal, and navigate to the folder that has the extracted program in it.
2. Run `./fake-apt`
3. Enjoy!
## About the legacy .NET 5 version
While the `Program.cs` file is still present in the repository, the project file has been removed. If you still intend to use the legacy version, you will need to create your own project and then compile it. Instructions are not provided as this version is no longer supported.
