all: projet
projetprelim: main.cpp lecture_psq.o lecture_fasta.o lecture_pin.o lecture_phr.o lecture_blosum.o smith_waterman.o blosum.h lecture.h
	g++ main.cpp lecture_psq.o lecture_fasta.o lecture_pin.o lecture_phr.o lecture_blosum.o smith_waterman.o -o projetprelim

lecture_psq.o : lecture_psq.cpp
	g++ -c lecture_psq.cpp
lecture_pin.o :
	g++ -c lecture_pin.cpp
lecture_phr.o :
	g++ -c lecture_phr.cpp
lecture_fasta.o :
	g++ -c lecture_fasta.cpp
lecture_blosum.o :
	g++ -c lecture_blosum.cpp
smith_waterman.o :
	g++ -c smith_waterman.cpp


projet:
	echo "Modifiez le fichier Makefile pour permettre la compilation de votre projet"
projetopt:
	echo "Modifiez le fichier Makefile pour permettre la compilation de votre projet"
clean: 
	rm *.o
