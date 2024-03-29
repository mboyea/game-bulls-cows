Bulls And Cows
===
A simple word guessing game.
---
This is the first game I built with C++. It was completed on 2019/01/24.

![Screenshot of the gameplay.](img/game-screen.png)

### Install on Windows
* [Install 7-Zip](https://7-zip.org/download.html).
* Install GCC. In the directory `C:\`, download and unzip [MinGW x86_64-XX.X.X-release-win32-seh-msvcrt-rt_vXX-revX.7z](https://github.com/niXman/mingw-builds-binaries/releases); the location of `g++.exe` should be `C:\mingw64\bin\g++.exe`.
* Add `C:\mingw64\bin` to the Windows Environment Variable [PATH](https://www.computerhope.com/issues/ch000549.htm).
* [Install Git Bash](https://git-scm.com/download/win); make sure to choose "Run Git from the Windows Command Prompt" during installation. This should result in a MINGW64 Bash installation that can access your Windows PATH while having access to Linux commands (ie. the `find` command).
* [Clone this repository](https://docs.github.com/en/repositories/creating-and-managing-repositories/cloning-a-repository#cloning-a-repository) to a directory on your computer. That directory will be referred to as `root`.
* Install [Make for Windows](https://gnuwin32.sourceforge.net/packages/make.htm); the location of `make.exe` should be `C:\Program Files (x86)\GnuWin32\bin\make.exe`.
* Add `C:\Program Files (x86)\GnuWin32\bin\` to the Windows Environment Variable [PATH](https://www.computerhope.com/issues/ch000549.htm).

From here, everything should be installed to compile & run this software.

### Install on Arch Linux
* [Clone this repository](https://docs.github.com/en/repositories/creating-and-managing-repositories/cloning-a-repository#cloning-a-repository) to a directory on your computer. That directory will be referred to as `root`.

From here, everything should be installed to compile & run this software.

### Compile & Run Scripts
To run a script, open a Bash (or equivalent) terminal within `root` and type the command.

| command | description |
|:----------- |:----------- |
| `make` | compile & link the program |
| `make clean` | remove all compiled files |

### Contribute
Unfortunately, this project doesn't support community contributions right now. Feel free to fork, but be sure to read the license.
