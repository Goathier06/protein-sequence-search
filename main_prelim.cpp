#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <string>
#include <unistd.h>
#include "lecture.h"
using namespace std ;


void print_header(string header, ostream &out = cout) {
	out << header << endl; 
	}




int main (int argc, char *argv[]) {
	if ( argc < 3) {
		cout << "Pas assez de fichiers donnés, veuillez compléter" << endl ;
	return 1 ;
}


	else {
		//Initialisations
        string fasta_path (argv[1]);
        string bdd_path (argv[2]) ;

		
		//Lecture du fichier contenant la proteine de requête
		string sequence = lect_fasta(fasta_path);
		
		//Recherche de la sequence identique a la proteine de requête
		int indice = lect_psq_prelim(bdd_path, sequence);
		
		if (indice == 1)
			cerr << "Impossible de trouver la protéine dans la base de données" << endl;
		
		//Recherche de la position de cette proteine	
		int pos = lect_pin(bdd_path, indice);
		
		//Recherche de son header a partir de sa position trouuvé dans le pin 
		string header = lect_phr(bdd_path, pos);
		print_header(header);
		
	return 0 ; 
	}
}

