#include <stdlib.h>
#include <fstream>
#include <cstring>
#include <iostream>
#include "lecture.h"
#include <vector>
#include <utility>
#include <algorithm>
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
void tri(array<pair<int,int>, 20>& classement, pair<int,int> couple)
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

array<pair<int,int>, 20> lect_psq(string blosum_path, string file_path, string seq_requete, int gop, int gep) 
{
	
	//Initialisations
	const string ext_psq = ".psq";
	int value;
	char seq;
	array<pair<int,int>, 20> classement;;
	string prot_complete = "";
	int m = seq_requete.length();
	int indice=0 ; // Position de la séquence dans la bdd
	BlosumMatrix matrice;
	matrice.lecture_blosum(blosum_path);
	
	
	// Ouverture du fichier psq
	ifstream bdd_psq (file_path + ext_psq, ios::binary);
	
	// Vérification de l'ouverture
	if (!bdd_psq.is_open()) 
		cerr << "Impossible d'ouvrir" << endl;
		
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
			if (!(prot_complete.empty()))
			{
				int score = smith_waterman(matrice,prot_complete,seq_requete,m,gop,gep);
				prot_complete = ""; // Réinitialise la séquence à chaque itération
				pair <int,int> couple = {score, indice};
				tri(classement, couple);
				//cout << prot_complete << "et score : " << couple.first <<" " << couple.second << endl;
				indice++;
			}
		}
	}
	
	bdd_psq.close();
	return classement; // La séquence n'a pas été trouvée
} 
