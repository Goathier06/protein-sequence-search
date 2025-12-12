#include <stdlib.h>
#include <fstream>
#include <cstring>
#include <iostream>
#include "lecture.h"
#include <vector>
#include <utility>
using namespace std ;

//Permet de convertir les octets en acides aminés selon les normes indiqués dans le fichier Far[10]
char decoder(int nbr) { 
	static const char table[28] = {
    '-','A','B','C','D','E','F','G','H','I','K','L','M','N','P','Q', 
    'R','S','T','V','W','X','Y','Z','U','*','O','J'};
	if (nbr<28) 
		return table[nbr];
	
	else {
		cerr << "Erreur" << endl;
		return '~'; //Permet d'éviter d'avoir un warning au moment de la compilation
	}
	
}	
void tri(vector<pair<int,int>>& classement, pair<int,int> couple)
{
	
	if (classement[classement.size()-1].first <= couple.first)
	{
		classement[classement.size()-1] = couple;
	}
	for (int i =0; i<classement.size(); i++)
	{
		int j = i;
		while ((j>0) and classement[j-1].first < classement[j].first)
		{
			pair<int,int> temp = classement[j];
			classement[j] = classement[j-1];
			classement[j-1] = temp;
			j--;
		}
	}
}

vector<pair<int,int>>  lect_psq(string blosum_path, string file_path, string seq_requete, int gop, int gep) 
{
	
	//Initialisations
	const string ext_psq = ".psq";
	int value;
	char seq;
	vector <pair<int,int>> classement(20,{0,0});
	string prot_complete = "";
	int indice=0 ; // Position de la séquence dans la bdd
	
	
	// Ouverture du fichier psq
	ifstream bdd_psq (file_path + ext_psq, ios::binary);
	
	// Vérification de l'ouverture
	if (!bdd_psq.is_open()) 
		cerr << "Impossible d'ouvrir" << endl;
		
	
	//smith_waterman(string file_path, string seq_requete);
	
	
	
		
	// Lire le fichier jusqu'à trouver la séquence de requête dans la base de données 
	while (bdd_psq.read(&seq, 1)) 
	{
		//cout<<"boucle infini"<<endl;
		value =0;
		memcpy(&value, &seq, 1);
		//cout << value << endl;
		if (value != 0) {
			prot_complete += decoder(value) ;
		}
		else 
		{
			if (prot_complete.empty())
			{
				//cout << "aie aie aie" << endl;
			}
			else
			{
				int test = smith_waterman(blosum_path,prot_complete,seq_requete,gop,gep);
				prot_complete = ""; // Réinitialise la séquence à chaque itération
				pair <int,int> couple = {test, indice};
				tri(classement, couple);
				//cout << prot_complete << "et score : " << couple.first <<" " << couple.second << endl;
				indice++;
			}
		}
	}
	
	bdd_psq.close();
	return classement; // La séquence n'a pas été trouvée
} 
