ttt: libttt.so main.o
	g++ -o build/ttt build/main.o -L./build -lttt -Wl,-rpath,'$$ORIGIN'

main.o: main.cpp build
	g++ -c -o build/main.o main.cpp

libttt.so: tiktaktoe.o
	g++ -shared -o build/libttt.so build/tiktaktoe.o

tiktaktoe.o: tiktaktoe.cpp build
	g++ -c -o build/tiktaktoe.o -fPIC tiktaktoe.cpp

build:
	mkdir build

clean:
	rm -vrf build

install:
	cp build/ttt /usr/games/ttt
	cp build/libttt.so /usr/lib/libttt.so

uninstall:
	rm /usr/games/ttt
	rm /usr/lib/libttt.so