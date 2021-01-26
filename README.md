# fake-apt
A fun little program I made in .NET 5, just goes through a fake apt install process. Simply load it up (instructions below), enter a package name after the pre-typed `sudo apt install`, and watch it go! Fool your friends... maybe.
## Running the thing
First, go to the Actions tab, then find the latest (successful) run and download the "fakeApt-latest" zip. Extract that to a folder you can access easily.
NOTE: You will need the .NET 5 Runtime installed for Windows 10 or Linux
### Windows
1. Open PowerShell, and navigate to the folder that you extracted the application to
2. Type `dotnet fakeApt.dll` and press enter
### Linux
1. Open your nearest terminal or terminal emulator, and navigate to the folder that you extracted the application to
2. Type `dotnet fakeApt.dll` and press enter
### macOS
1. Open the folder that you extracted the application to in Finder
2. Double click the .dll
