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


//22826816

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
	

	bdd_pin.seekg(8, std::ios::beg);
	
	bdd_pin.read(reversed_bytes, 4);
	reverse(reversed_bytes);
	memcpy(&val, reversed_bytes, 4);
	
	
	bdd_pin.seekg(val, std::ios::cur);
	
	bdd_pin.read(reversed_bytes, 4);
	reverse(reversed_bytes);
	memcpy(&val, reversed_bytes, 4);
	
	
	bdd_pin.seekg(8 + val + indice*4, std::ios::cur);
	
	
	
	bdd_pin.read(reversed_bytes, 4);
	reverse(reversed_bytes);
	memcpy(&val, reversed_bytes, 4);
	cout << "on a trouvé la position dans le pin" << endl;
	cout << val << endl;
	//Fermeture du fichier 
	bdd_pin.close();
	return val; //Retourne la position des informations de la séquence 
				// dans le fichier phr
}
