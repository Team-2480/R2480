# On Windows

Install [chocolatey](https://chocolatey.org/install).

```batch
winget install mingw
choco install make wget
```
Then run `make install_windows`.

# On MacOS

Verfiy you have `make` and `clang++`.

[Download raylib](https://github.com/raysan5/raylib/releases/download/5.5/raylib-5.5_macos.tar.gz) and extract into raylib/
Thus your directory should look like:
```
T2480
├───build
├───raylib
│   ├───include
│   └───lib
└───src
```

Run `make` and pray everything compiles.

# On Linux

Figure it out.