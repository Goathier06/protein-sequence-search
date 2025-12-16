#include <stdlib.h>
#include <fstream>
#include <cstring>
#include <iostream>
#include "lecture.h"
#include <vector>
#include <utility>
#include <algorithm>
using namespace std ;

char decoder(int nbr){ 
	//Permet de convertir les octets en acides aminés 
	//selon les normes indiquées dans le fichier Far[10]
	
	static const char table[28] = {
    '-','A','B','C','D','E','F','G','H','I','K','L','M','N','P','Q', 
    'R','S','T','V','W','X','Y','Z','U','*','O','J'};
	if (nbr<28) 
		return table[nbr];
	
	else 
	{
		cerr << "Erreur" << endl;
		return '~'; //Permet d'éviter d'avoir un warning au moment de la compilation
	}
	
}	

void tri(array<pair<int,int>, 20>& classement, pair<int,int> couple){
	//Fonction permettant d'insérer une protéine dans le classement 
	//et d'ensuite trier par ordre score décroissant
	
	if (classement[classement.size()-1].first <= couple.first) //Si la séquence a un meilleur score que le plus petit score du tableau, son couple est inséré
	{
		classement[classement.size()-1] = couple;
	}
	
	for (int i =0; i<classement.size(); i++) //Tri par insertion
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

array<pair<int,int>, 20> lect_psq(string blosum_path, string file_path, string seq_requete, int gop, int gep){
	//Fonction renvoyant les 20 meilleures protéines à partir des scores d'alignement calculés dans la fonctions smith_waterman
	//pour chaque protéine de la base de données
	
	//Initialisations
	const string ext_psq = ".psq";
	int value;
	char seq;
	array<pair<int,int>, 20> classement;
	string prot_complete = "";
	int m = seq_requete.length();
	int indice=0 ; // Position de la séquence dans la bdd
	BlosumMatrix matrice;
	matrice.lecture_blosum(blosum_path);
	
	
	//Ouverture du fichier psq
	ifstream bdd_psq (file_path + ext_psq, ios::binary);
	
	//Vérification de l'ouverture
	if (!bdd_psq.is_open()) 
		cerr << "Impossible d'ouvrir" << endl;
		
	//Lecture du fichier jusqu'à trouver la séquence de requête dans la base de données 
	while (bdd_psq.read(&seq, 1))
	{
		value =0;
		memcpy(&value, &seq, 1);
		if (value != 0) 
		{
			prot_complete += decoder(value) ;
		}
		else 
		{
			if (!(prot_complete.empty()))
			{
				int score = smith_waterman(matrice,prot_complete,seq_requete,m,gop,gep); //Calcul du score grâce à l'algorithme de Smith Waterman
				prot_complete = ""; //Réinitialise la séquence à chaque itération
				pair <int,int> couple = {score, indice}; //Score et indice de la protéine réunis
				tri(classement, couple);
				indice++;
			}
		}
	}
	
	bdd_psq.close(); //Fermeture du fichier
	return classement; 
} 
