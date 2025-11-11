#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <cstring>
using namespace std ;

string lect_phr(string file_path, int pos) {
	
	const string ext_phr = ".phr";
	int valeur = 0;
	char oct;
	char lettre;
	string header;
	
	ifstream bdd_phr (file_path + ext_phr, ios::binary);
	if (!bdd_phr.is_open()) 
		cerr << "Impossible d'ouvrir"<< endl;
		
	for (int j = 0; j < pos;j++) {
		bdd_phr.read(&oct, 1);
	}
	do  {
		bdd_phr.read(&oct,1);
		memcpy(&valeur,&oct, 1);
	} while (valeur != 26);
	
	bdd_phr.read(&oct,1); //On lit le byte qui précède la chaine de caractères comme mentionné dans [Far10]
	while (bdd_phr.read(&lettre,1)) {
		if (lettre != ' ') {
			header += lettre;
		}
		else {
			break;
		}
		
	}
	bdd_phr.close();
	return header;
	
}
