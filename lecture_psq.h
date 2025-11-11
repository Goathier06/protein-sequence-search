#include <stdlib.h>
#include <fstream>
#include <cstring>
using namespace std ;


char decoder(int nbr) {
	static const char table[28] = {
    '-','A','B','C','D','E','F','G','H','I','K','L','M','N','P','Q', 
    'R','S','T','V','W','X','Y','Z','U','*','O','J'};
	if (nbr<28) 
		return table[nbr];
	
	else {
		cerr << "Erreur" << endl;
		return '~';
	}
	
}	

int lect_psq(string file_path, string seq_requete) {
	const string ext_psq = ".psq";
	int value;
	char seq[1];
	string prot_complete = "";
	int indice=0 ;
	
	

	ifstream bdd_psq (file_path + ext_psq, ios::binary);
	
	if (!bdd_psq.is_open()) 
		cerr << "Impossible d'ouvrir" << endl;
		
	while (bdd_psq.read(seq, 1)) {
		value =0;
		memcpy(&value, seq, 1);
		if (value != 0) {
			prot_complete += decoder(value) ;
		}
		else {
			indice++;
			if (seq_requete == prot_complete) {
				return indice;
			}
			prot_complete = "";
		}
	}
	bdd_psq.close();
	return 1;
} 
