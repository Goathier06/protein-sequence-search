#include <stdlib.h>
#include <fstream>
using namespace std ;

struct proteine {
	string identifiant;
	string sequence ;
};

string lect_fasta(string file_path){
	proteine prot; 	
	ifstream fichier (file_path);
	
	if (fichier.is_open()) {
            getline(fichier, prot.identifiant) ;
        }
		
        //cout << prot.identifiant << endl ;
        
        string line = ""; 
        while (getline(fichier, line)){
                prot.sequence += line;
            }
        //cout << "Séquence de la protéine de requête :" << endl << prot.sequence << endl ;

        fichier.close();
        return prot.sequence;
}

