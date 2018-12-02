TestRule: main.cpp
	g++ -g main.cpp Shape.h Point.h Point.cpp Line.h Line.cpp Triangle.h Triangle.cpp Polygon.h Polygon.cpp -o main.exe -static-libgcc -static-libstdc++