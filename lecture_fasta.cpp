#include <stdlib.h>
#include <fstream>
#include <iostream>
using namespace std ;

string lect_fasta(string file_path){
	//Fonction permettant de lire le fichier .fasta
	//et le stocker dans la proteine prot
	
	string sequence;
	string line = ""; 
	ifstream fichier (file_path); //Ouverture du fichier .fasta
	
	if (fichier.is_open()) 
	{ 										
		getline(fichier,line);
        line = "";
        while (getline(fichier, line)) //Lecture ligne par ligne de la séquence
        {	
			sequence += line;
        }
        fichier.close(); //Fermeture du fichier à la fin de la lecture
        return sequence;
	}
	else 
	{
		fichier.close();
		cerr << "Impossible d'ouvrir le fichier fasta" << endl;
		return "0";
	}
}
