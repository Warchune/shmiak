.PHONY: build install uninstall clean

build:
	gcc -o ./build/shmiak main.c -lm

install: build
	cp ./build/shmiak /usr/bin/shmiak

uninstall: build
	rm -f  /usr/bin/shmiak

clean:
	rm -Rf ./build/*