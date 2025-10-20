#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <string>
using namespace std ;

struct proteine {
	string identifiant;
	string sequence ;
};

int main (int argc, char *argv[]) {
	if ( argc < 2) {
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
	return 0 ; 
}
}

