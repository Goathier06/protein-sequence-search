#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <cstring>
using namespace std ;

//	Fonction permettant d'inverser les octets lu dans le fichier pin 
//	Cela permet de régler les erreurs d'endianess
void reverse(char mot[]) { 
    char inter = mot[0];
        mot[0] = mot[3];
        mot[3] = inter;
        inter = mot[1];
        mot[1] = mot[2];
        mot[2] = inter;
    }



int lect_pin(string file_path, int indice) {
	
	//Initialisations
	const string ext_pin = ".pin";
	int val;
	int longueur_titre =100; //Initalisation de longueur titre à une grande valeur 
	char reversed_bytes[4];
	
	//Ouverture du fichier pin
	ifstream bdd_pin (file_path + ext_pin, ios::binary);
	
	//Vérification de l'ouverture
	if (!bdd_pin.is_open()) 
		cerr << "Impossible d'ouvrir"<< endl;
	
	// Boucle qui itère jusqu'à l'indice où se trouve les informations 
	// de notre séquence dans le fichier phr
	for (int i = 0; i<=indice+6;i++) {
	bdd_pin.read(reversed_bytes, 4);
	reverse(reversed_bytes);
	memcpy(&val, reversed_bytes, 4);
	
	// Etant donné que le fichier pin contient des chaine de caractères
	// à longueur inconnue, il faut incrémenter l'indice de manière à 
	// prendre en compte ces chaines de caractères dans la lecture
		if (i == 2) {
			longueur_titre = val/4 ; 
			indice += longueur_titre;
			}
			
		if (i == 2 + longueur_titre + 1 ) {  	
			int longueur_timestamp = val/4 ;
			indice += longueur_timestamp;
			}
		}
		
	//Fermeture du fichier 
	bdd_pin.close();
	return val; //Retourne la position des informations de la séquence 
				// dans le fichier phr
}
