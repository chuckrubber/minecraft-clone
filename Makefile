test : build/main
	./build/main

clean :
	rm build/*

build/glad.o : src/glad.c
	g++ src/glad.c -c -o build/glad.o -Iinclude

build/main.o : src/main.cpp
	g++ src/main.cpp -c -o build/main.o -Iinclude

build/window.o : src/window.cpp
	g++ src/window.cpp -c -o build/window.o -Iinclude

build/main : build/glad.o build/main.o build/window.o
	g++ build/glad.o build/main.o build/window.o -o build/main -Iinclude -lglfw3 -lGL -lm -ldl -lXinerama -lXrandr -lXi -lXcursor -lX11 -lXxf86vm -lpthread