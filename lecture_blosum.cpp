#include <vector>
#include <string>
#include <map>
#include <fstream>
#include <iostream>
#include <sstream>
#include "blosum.h"
using namespace std ;

void BlosumMatrix:: lecture_blosum(string file_path){
	ifstream fichier (file_path); //Ouverture du fichier
	
	if (!fichier.is_open()) {
		std::cerr << "Impossible d'ouvrir"<<endl;
	}
	else{
		string line;
		vector<int> ColumnsOrder; //Mémorise l'ordre des colonnes
		stringstream stream(line); //Flux pour découper la ligne charactère
		// par charactère et le décoder
		char letter; //Variable temporaire pour stocker la lettre a décoder
		char score; //Variable temporaire pour stocker les scores
		while (getline(fichier, line)){ //Lit chaque ligne et la stock dans line
			// Ligne vide ou commentaire: ignorer
			if (line.empty() || line[0]=='#'|| line[0]==' ') continue;
			// Ligne avec les titres des colonnes:
			// Décoder
			// Stocker dansle vecteur qui leur est consacrée
			else if (ColumnsOrder.empty() && line[0]==' '){
				while (stream>>letter){
				ColumnsOrder.push_back(Decodeur(letter));
				}
			}
			//Le reste des lignes: contient les scores
			else{
				int m = Decodeur(letter); //Ligne sur laquelle on se trouve
				int i= 0; //Colonne sur laquelle on se trouve
				while (stream>>score){
					matrice[m][ColumnsOrder[i]]= score;
					i++;					
				}
			fichier.close();
			}	
		}
	}
}
					
					
				
				
				
	
	
