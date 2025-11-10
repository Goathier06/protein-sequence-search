#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <unistd.h>
#include "reverse.h"
#include "decoder.h"
using namespace std ;

struct proteine {
	string identifiant;
	string sequence ;
};

int main (int argc, char *argv[]) {
	if ( argc < 3) {
		cout << "Pas assez de fichiers donnés, veuillez compléter" << endl ;
	return 1 ;
}
	else {
		proteine prot;
		ifstream fichier (argv[1]) ;


		if (fichier.is_open()) {
			getline(fichier, prot.identifiant) ;
		}
	cout << "Identifiant de la protéine de requête :" << endl << prot.identifiant << endl ;
	string line = "";
	while (getline(fichier, line)){
		prot.sequence += line;
	}
	cout << "Séquence de la protéine de requête :" << endl << prot.sequence << endl ;
	
	fichier.close();



// Permet de lire le fichier PIN //
/*
	int value;
	char reversed_bytes[4];
	
	ifstream bdd (argv[2], ios::binary);
	if (bdd.is_open()) {
	do {
		
		//bdd.read(reversed_bytes, 4);
	    reverse(reversed_bytes);
		std::memcpy(&value, reversed_bytes, 4);
		cout << seq << endl; 
	}
	while (true);
	}
*/


// Permet de parser le fichier psq entièrement mais reste encore à être optimiser

int value;
char seq[0];
string prot_complete = "";


ifstream bdd (argv[2], ios::binary);
do {
	bdd.read(seq, 1);
	std::memcpy(&value, seq, 1);
	//cout <<value<< endl;
	if (value != 0) {
		prot_complete += decoder(value) ;
	}
		
	else {
		cout << "check" << endl;
		if (prot.sequence == prot_complete) 
			cout << "EUREKAAAAAA" << endl;
		
	}
	
} while (seq[0] != EOF);






	return 0 ; 
}
}

