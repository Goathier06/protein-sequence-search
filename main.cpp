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
        string chem_base (argv[2]) ;


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
       // string cmd = "./makeblastdb -in " + chem_base + " -dbtype prot -blastdb_version 4 -out database/extraits";
       // int ext = system(cmd.c_str());
       // if (ext != 0){
       //     cout << "Erreur d'extraction :/" << endl;
       //}
	






// Permet de parser le fichier psq entièrement mais reste encore à être optimiser

int value;
char seq[0];
string prot_complete = "";
int indice=0 ;

ifstream bdd_psq ("database/extraits.psq", ios::binary);
while (seq[0] != EOF) {
	
	bdd_psq.read(seq, 1);
	value =0;
	std::memcpy(&value, seq, 1);
	//cout <<value<< endl;
	if (value != 0) {
		prot_complete += decoder(value) ;
	}
	else {
		indice++;
		if (prot.sequence == prot_complete) {
			cout << prot_complete << endl << endl;
			cout << indice << endl;
			break;
		}
		prot_complete = "";
	}
} 


// Permet de lire le fichier PIN //

	int val;
	int longueur_titre =100;
	char reversed_bytes[4];
	ifstream bdd_pin ("database/extraits.pin", ios::binary);
	if (bdd_pin.is_open()) {
		for (int i = 0; i<=indice+6;i++) {
		//cout << longueur_titre <<endl;
		//cout <<indice<< endl;
		bdd_pin.read(reversed_bytes, 4);
	    reverse(reversed_bytes);
		std::memcpy(&val, reversed_bytes, 4);
		//cout << val << endl; 
			if (i == 2) {
			longueur_titre = val/4 ;
			//cout << longueur_titre << endl;
			indice += longueur_titre;
			}
			if (i == 2 + longueur_titre + 1 ) {
			int longueur_timestamp = val/4 ;
			indice += longueur_timestamp;
			}
		}
	}
	int pos = val;
	cout << pos << endl;
	bdd_pin.close();
	
	
	//LIRE LE FICHIER PHR
	int valeur = 0;
	char oct[0];
	char header[22];
	ifstream bdd_phr ("database/extraits.phr", ios::binary);
	if (bdd_phr.is_open()) {
		for (int j = 0; j < pos;j++) {
			bdd_phr.read(oct, 1);
		}
		while (valeur != 26) {
			bdd_phr.read(oct,1);
			std::memcpy(&valeur,oct, 1);
		}
		bdd_phr.read(header,22);
		cout << header << endl;
	}
	bdd_phr.close();

	
	
	
	
	
return 0 ; 
}
}

