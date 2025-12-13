all: projet
projetprelim: main.cpp lect_psqtest.o lecture_fasta.o lecture_pin.o lecture_phr.o lecture_blosum.o smith_waterman.o lecture.h
	g++ main.cpp lect_psqtest.o lecture_fasta.o lecture_pin.o lecture_phr.o lecture_blosum.o smith_waterman.o -o projetprelim
	
projet: main.cpp lecture_psq.o lecture_fasta.o lecture_pin.o lecture_phr.o lecture_blosum.o smith_waterman.o lecture.h
	g++ main.cpp lecture_psq.o lecture_fasta.o lecture_pin.o lecture_phr.o lecture_blosum.o smith_waterman.o -o projet

lecture_psq.o : lecture_psq.cpp
	g++ -c lecture_psq.cpp
lecture_pin.o : lecture_pin.cpp
	g++ -c lecture_pin.cpp
lecture_phr.o : lecture_phr.cpp
	g++ -c lecture_phr.cpp
lecture_fasta.o : lecture_fasta.cpp
	g++ -c lecture_fasta.cpp
lecture_blosum.o : lecture_blosum.cpp
	g++ -c lecture_blosum.cpp
smith_waterman.o : smith_waterman.cpp
	g++ -c smith_waterman.cpp

projetopt:
	echo "Modifiez le fichier Makefile pour permettre la compilation de votre projet"
clean: 
	rm *.o
