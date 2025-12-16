#include <vector>
#include <string>
#include <map>
#include <fstream>
#include <iostream>
#include <sstream>
#include "lecture.h"
using namespace std ;

void BlosumMatrix:: lecture_blosum(string file_path ){
	//Lis le fichier BLOSUM62 pour crée la matrice blosum	
	
	ifstream fichier (file_path); //Ouverture du fichier
	if (!fichier.is_open()) 
	{
		std::cerr << "Impossible d'ouvrir"<<endl;
	}
	else
	{
		string line;
		vector<int> ColumnsOrder; //Mémoriser l'ordre des colonnes par charactère et le décoder
		char letter; //Variable temporaire pour stocker la lettre a décoder
		int score; //Variable temporaire pour stocker les scores
		
		while (getline(fichier, line)) //Lit chaque ligne et la stocke dans line
		{ 
			
			//Ligne vide ou commentaire à ignorer
			if (line.empty() || line[0] == '#') continue;
			 
			stringstream stream(line); //Flux pour découper la ligne en charactères
			
			//Ligne avec les titres des colonnes:
			//Décoder
			//Stocker dans le vecteur qui leur est consacré
			if (ColumnsOrder.empty() && line[0]==' ')
			{ 
				while (stream>>letter)
				{
				ColumnsOrder.push_back(Decodeur(letter));
				}
			}
			//Le reste de la ligne contenant les scores
			else
			{
				char firstletter;
				stream >> firstletter;
				int m = Decodeur(firstletter); //Ligne sur laquelle on se trouve
				int i= 0; //Colonne sur laquelle on se trouve
				while (stream>>score)
				{
					matrice[m][ColumnsOrder[i]]= score;
					i++;					
				}
			
			}	
		}
		fichier.close(); //Fermeture du fichier
	}
}


int BlosumMatrix::getScore(int a, int b){
	//Retourne le score pour une combinaison de deux acides aminés donnés
	
	return matrice[a][b];
}
					
					
				
				
				
	
	
