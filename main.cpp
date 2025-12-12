#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <string>
#include <unistd.h>
#include "lecture.h"
#include "blosum.h"

using namespace std ;
class BlosumMatrix;


void print_header(string header, ostream &out = cout) {
	out << header  << endl; 
	}




int main (int argc, char *argv[]) {
	if ( argc < 6) {
		cout << "Pas assez de fichiers donnés, veuillez compléter" << endl ;
	return 1 ;
}


	else {
		//Initialisations
        string fasta_path (argv[1]);
        string bdd_path (argv[2]) ;
        string blosum_path(argv[3]);
        int gap_open_penalty = stoi(argv[4]);
        int gap_extension_penalty = stoi(argv[5]);

		
		//Lecture du fichier contenant la proteine de requête
		string sequence = lect_fasta(fasta_path);
		
		//Recherche de la sequence identique a la proteine de requête
		vector<pair<int,int>>  indices = lect_psq(blosum_path,bdd_path, sequence, gap_open_penalty+gap_extension_penalty, gap_extension_penalty);
		/*
		cout << indices[0].first << endl;
		cout << indices[0].second << endl;
		cout << indices[5].first << endl;
		cout << indices[5].second << endl;
		cout << "premier : "<< indices[17].first << endl;
		cout << "second : " << indices[17].second << endl;
		cout << "premier : "<< indices[18].first << endl;
		cout << "second : " << indices[18].second << endl;
		cout << "premier : "<< indices[19].first << endl;
		cout << "second : " << indices[19].second << endl;
		*/
		//Recherche de la position de cette proteine	
		for (int i = 0; i< indices.size(); i++)
		{
			int pos = lect_pin(bdd_path, indices[i].second);   //
			string header = lect_phr(bdd_path, pos);
			print_header(header + " " + to_string(indices[i].first));
			//cout << header << endl;
			//cout << indices[i].second << endl;
		}	
		//Recherche de son header a partir de sa position trouuvé dans le pin 
		
	

		
				
	return 0 ; 
	}
}

