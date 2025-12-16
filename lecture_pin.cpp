#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <cstring>
using namespace std ;

void reverse(char mot[]){ 
	//Fonction permettant d'inverser les octets lus dans le fichier .pin 
	//Cela permet de régler les erreurs d'endianess
	
    char inter = mot[0];
        mot[0] = mot[3];
        mot[3] = inter;
        inter = mot[1];
        mot[1] = mot[2];
        mot[2] = inter;
}


int lect_pin(string file_path, int indice){
	//Fonction permettant de récupérer la position de la protéine
	//dans la base de données
	
	//Initialisations
	const string ext_pin = ".pin";
	int val; 
	char reversed_bytes[4];
	
	//Ouverture du fichier pin
	ifstream bdd_pin (file_path + ext_pin, ios::binary);
	
	//Vérification de l'ouverture
	if (!bdd_pin.is_open()) 
		cerr << "Impossible d'ouvrir"<< endl;
	
	//Déplacement jusqu'aux 4 octets contenant la taille du titre
	bdd_pin.seekg(8, std::ios::beg);
	
	//Lecture des 4 octets
	bdd_pin.read(reversed_bytes, 4);
	reverse(reversed_bytes);
	memcpy(&val, reversed_bytes, 4);
	const int longueur_titre = val;
	
	//Déplacement de la longueur du titre
	bdd_pin.seekg(val, std::ios::cur);
	
	//Lecture des octets contenant la longueur du timestamp
	bdd_pin.read(reversed_bytes, 4);
	reverse(reversed_bytes);
	memcpy(&val, reversed_bytes, 4);
	const int longueur_timestamp = val;
	int rest=8;
	
	if (((longueur_timestamp + longueur_titre) % 8) != 0) //Vérification que le dernier octet est bien un multiple de 8
		rest = (val+longueur_titre+8)%8;

	bdd_pin.seekg(16 + val + (8-rest) + indice*4, std::ios::cur); //16 = 4 + 2*4 + 4 octets, voir NCBI BLAST Database Format (2010)
	
	//Lecture des octet contenant la position recherchée
	bdd_pin.read(reversed_bytes, 4);
	reverse(reversed_bytes);
	memcpy(&val, reversed_bytes, 4);
	bdd_pin.close(); //Fermeture du fichier 
	
	return val; //Retourne la position des informations de la séquence dans le fichier phr
}

