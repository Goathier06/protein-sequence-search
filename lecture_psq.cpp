#include <stdlib.h>
#include <fstream>
#include <cstring>
#include <iostream>
#include "lecture.h"
using namespace std ;

//Permet de convertir les octets en acides aminés selon les normes indiqués dans le fichier Far[10]
char decoder(int nbr) { 
	static const char table[28] = {
    '-','A','B','C','D','E','F','G','H','I','K','L','M','N','P','Q', 
    'R','S','T','V','W','X','Y','Z','U','*','O','J'};
	if (nbr<28) 
		return table[nbr];
	
	else {
		cerr << "Erreur" << endl;
		return '~'; //Permet d'éviter d'avoir un warning au moment de la compilation
	}
	
}	

int lect_psq(string blosum_path, string file_path, string seq_requete, int gop, int gep) {
	
	//Initialisations
	const string ext_psq = ".psq";
	int value;
	char seq;
	string prot_complete = "";
	int indice=0 ; // Position de la séquence dans la bdd
	
	
	// Ouverture du fichier psq
	ifstream bdd_psq (file_path + ext_psq, ios::binary);
	
	// Vérification de l'ouverture
	if (!bdd_psq.is_open()) 
		cerr << "Impossible d'ouvrir" << endl;
		
	
	//smith_waterman(string file_path, string seq_requete);
	
	
	
		
	// Lire le fichier jusqu'à trouver la séquence de requête dans la base de données 
	while (bdd_psq.read(&seq, 1)) {
		//cout<<"boucle infini"<<endl;
		value =0;
		memcpy(&value, &seq, 1);
		//cout << value << endl;
		if (value != 0) {
			prot_complete += decoder(value) ;
		}
		else {
			if (prot_complete.empty()){
				//cout << "aie aie aie" << endl;
				}
			else{
			int test = smith_waterman(blosum_path,prot_complete,seq_requete,gop,gep);
			//cout << prot_complete << endl;
			//cout << test << endl;
			// Incrémentation de l'indice à chaque itération
			/*if (seq_requete == prot_complete) {
				return indice;	// Retourne le bonne indice */
			prot_complete = ""; // Réinitialise la séquence à chaque itération
			indice++;
			//cout << indice << endl;
	
			}
		}
		}
	
	bdd_psq.close();
	return -1; // La séquence n'a pas été trouvée
} 
