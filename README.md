# fake-apt
A fun little program I originally made in .NET 5, and then rewrote in C. Able to immitate most major `apt` functions, and more are being added with some frequency. Run it with the same syntax you'd use to install something will real APT, and watch it go! (Directions below) Fool your friends... maybe.
## Running the thing
First, download the version of fake-apt that works on your OS from releases. If you'd like the latest build instead, use the links below.

**Linux:** [Download](https://nightly.link/NinjaCheetah/fake-apt/workflows/main/main/fake-apt-linux.zip)

**macOS:** [Download](https://nightly.link/NinjaCheetah/fake-apt/workflows/main/main/fake-apt-macOS.zip)

**Windows:** [Download](https://nightly.link/NinjaCheetah/fake-apt/workflows/main/main/fake-apt-windows.zip)

Directions for getting the list of currently available commands are below. Note that the command syntax is deisgned to be identical to real `apt`'s syntax.

### macOS
1. Open a terminal, and navigate to the folder that has the extracted program in it.
2. Run `./fake-apt`
3. Enjoy!
### Linux
1. Open a terminal, and navigate to the folder that has the extracted program in it.
2. Run `./fake-apt`
3. Enjoy!
### Windows
1. Open CMD or PowerShell, and navigate to the folder that has the extracted program in it.
2. Run `.\fake-apt.exe`
3. Enjoy!
## Limitations
Currently, you can only install/reinstall 1 package at a time, rather than multiple like you can with real `apt`. `update`, `upgrade` and `full-upgrade` will return the same results every time, so no new updates will ever appear to be available.
## About the legacy .NET 5 version
The legacy .NET 5 version of fake-apt is now completely deprecated as the C version now supports Windows. It's source has been removed.
