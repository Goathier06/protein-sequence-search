#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <cstring>
using namespace std ;


void reverse(char mot[]) {
    char inter = mot[0];
        mot[0] = mot[3];
        mot[3] = inter;
        inter = mot[1];
        mot[1] = mot[2];
        mot[2] = inter;
    }



int lect_pin(string file_path, int indice) {
	
	const string ext_pin = ".pin";
	int val;
	int longueur_titre =100;
	char reversed_bytes[4];
	ifstream bdd_pin (file_path + ext_pin, ios::binary);
	
	
	if (!bdd_pin.is_open()) 
		cerr << "Impossible d'ouvrir"<< endl;
		
	for (int i = 0; i<=indice+6;i++) {
	bdd_pin.read(reversed_bytes, 4);
	reverse(reversed_bytes);
	memcpy(&val, reversed_bytes, 4);

		if (i == 2) {
			longueur_titre = val/4 ;
			indice += longueur_titre;
			}
			
		if (i == 2 + longueur_titre + 1 ) {
			int longueur_timestamp = val/4 ;
			indice += longueur_timestamp;
			}
		}
	bdd_pin.close();
	return val;
}
