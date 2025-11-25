#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <cstring>
#include <unistd.h>
using namespace std ;


//Fonction permettant de retrouver le nom de la proteine
// a partir de sa position dans le document
string lect_phr(string file_path, int pos) {
	//Initialisations
	const string ext_phr = ".phr";
	int valeur;
	char oct;
	char lettre;
	string header;
	ifstream bdd_phr (file_path + ext_phr, ios::binary); //Ouverture du fichier
	if (!bdd_phr.is_open()) {
		cerr << "Impossible d'ouvrir"<< endl;
	}
	bdd_phr.seekg(pos, std::ios::beg);
	
	while (valeur != 26 && bdd_phr.read(&oct,1))  {
		memcpy(&valeur,&oct, 1);
	} 
	
	bdd_phr.read(&oct,1); //On lit le byte qui précède la chaine de caractères comme mentionné dans [Far10]
	while (bdd_phr.read(&lettre,1)) {
		if (lettre != ' ') {
			header += lettre; //Construction du header
		}
		else {
			break;
		}
		
	}
	bdd_phr.close(); //Fermeture du fichier
	return header;
	
}
