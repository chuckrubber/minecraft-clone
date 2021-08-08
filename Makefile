test : build/main
	./build/main

clean :
	rm build/*

build/glad.o : src/glad.c
	gcc src/glad.c -c -o build/glad.o -Iinclude

build/main.o : src/main.c
	gcc src/main.c -c -o build/main.o -Iinclude

build/main : build/glad.o build/main.o
	gcc build/glad.o build/main.o -o build/main -Iinclude -lGL -lGLU -lglfw3 -lX11 -lXxf86vm -lXrandr -lpthread -lXi -ldl -lXinerama -lXcursor -lglfw3