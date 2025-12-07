all: projet
projetprelim: main.cpp lecture_psq.cpp lecture_fasta.cpp lecture_pin.cpp lecture_phr.cpp lecture_blosum.cpp
	g++ main.cpp lecture_psq.cpp lecture_fasta.cpp lecture_pin.cpp lecture_phr.cpp lecture_blosum.cpp -o projetprelim

projet:
	echo "Modifiez le fichier Makefile pour permettre la compilation de votre projet"
projetopt:
	echo "Modifiez le fichier Makefile pour permettre la compilation de votre projet"
clean: 
	rm *.o
