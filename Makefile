OBJS = build/main.o build/scheduler.o
HEADERS = $(wildcard src/*.h)
LDFLAGS = -Lraylib/lib/ -lraylib -lgdi32 -lwinmm
PROGRAM = build/R2480.exe
CC=g++

ifneq ($(OS),Windows_NT)
	CC=clang++
	PROGRAM = build/R2480
endif

all: $(OBJS)
	$(CC) $(OBJS) $(RAYLIB) -o $(PROGRAM) $(LDFLAGS)

build/%.o: src/%.cpp $(HEADERS)
	$(CC) -c $< -o $@

install_windows:
	wget https://github.com/raysan5/raylib/releases/download/5.5/raylib-5.5_win64_mingw-w64.zip
	move raylib-5.5_win64_mingw-w64.zip build/raylib-5.5_win64_mingw-w64.zip
	tar -xf build/raylib-5.5_win64_mingw-w64.zip
	move raylib-5.5_win64_mingw-w64 raylib