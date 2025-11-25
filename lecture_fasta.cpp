#include <stdlib.h>
#include <fstream>
#include <iostream>
using namespace std ;

struct proteine {
	string identifiant;
	string sequence ;
};

//Fonction permettangt de lire le fichier fasta
// et le stocker dans la proteine prot
string lect_fasta(string file_path){
	proteine prot; 	
	ifstream fichier (file_path); //Ouverture du fichier fasta
	
	if (fichier.is_open()) {
            getline(fichier, prot.identifiant) ; //Lecture ligne par ligne
												//et stockée dans la partie identifiant				
        }
		
  
        
        string line = ""; 
        while (getline(fichier, line)){		//lecture ligne par ligne de la séquence
                prot.sequence += line;
            }

        fichier.close(); 	//Fermeture du fichier à la fin de la lecture
        return prot.sequence;
}

