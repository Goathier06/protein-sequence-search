all: projet
projetprelim: 
	g++ main.cpp -o main

projet:
	g++ main.cpp -o main
	echo "Modifiez le fichier Makefile pour permettre la compilation de votre projet"
projetopt:
	echo "Modifiez le fichier Makefile pour permettre la compilation de votre projet"
clean: 
	rm *.o
