# fake-apt
A fun little program I originally made in .NET 5, and then rewrote in C. Able to immitate most major `apt` functions, and more are being added with some frequency. Run it with the same syntax you'd use to install something will real APT, and watch it go! (Directions below) Fool your friends... maybe.
## Running the thing
First, download the version of fake-apt that works on your OS from releases. If you'd like the latest build instead, use the links below.

**Linux:** [Download](https://nightly.link/NinjaCheetah/fake-apt/workflows/main/main/fake-apt-linux.zip)

**macOS:** [Download](https://nightly.link/NinjaCheetah/fake-apt/workflows/main/main/fake-apt-macOS.zip)

**Windows:** [Download](https://nightly.link/NinjaCheetah/fake-apt/workflows/main/main/fake-apt-windows.zip)

Basic directions are available below. All of `fake-apt`'s syntax mimics `apt`'s.

## Unfamiliar with `apt`?
Run `./fake-apt` (or `.\fake-apt.exe` on Windows) in your favorite terminal or command prompt to see a list of `apt`'s commands. Every command you see listed is functional (to a degree). If you need some help with the syntax, note that not only are `apt`'s commands mimicked, but the error messages are too! If those aren't enough to tell you how to use it, any guide online on how to use `apt` should suffice.

## Limitations
Currently, you can only install/reinstall/remove 1 package at a time, rather than multiple like you can with real `apt`. `update`, `upgrade` and `full-upgrade` will return the same results every time, so no new updates will ever appear to be available. `edit-sources` just returns an error about not being able to unlock the database, due to the difficulties of opening an editor on all possible platforms.
