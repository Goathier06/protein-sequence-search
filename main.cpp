#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <string>
#include <unistd.h>
#include "lecture.h"
#include "blosum.h"

using namespace std ;
class BlosumMatrix;


void print_header(string header, ostream &out = cout) {
	out << header << endl; 
	}




int main (int argc, char *argv[]) {
	if ( argc < 6) {
		cout << "Pas assez de fichiers donnés, veuillez compléter" << endl ;
	return 1 ;
}


	else {
		//Initialisations
        string fasta_path (argv[1]);
        string bdd_path (argv[2]) ;
        string blosum_path(argv[3]);
        int gap_open_penalty = stoi(argv[4]);
        int gap_extension_penalty = stoi(argv[5]);

		
		//Lecture du fichier contenant la proteine de requête
		string sequence = lect_fasta(fasta_path);
		
		//Recherche de la sequence identique a la proteine de requête
		int indice = lect_psq(blosum_path,bdd_path, sequence, gap_open_penalty+gap_extension_penalty, gap_extension_penalty);
		
		if (indice == -1)
			cerr << "Impossible de trouver la protéine dans la base de données" << endl;
		
		//Recherche de la position de cette proteine	
		int pos = lect_pin(bdd_path, indice);
		
		//Recherche de son header a partir de sa position trouuvé dans le pin 
		string header = lect_phr(bdd_path, pos);
		print_header(header);
	

		
				
	return 0 ; 
	}
}

