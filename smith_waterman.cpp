#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <string>
#include <unistd.h>
#include <algorithm>
#include <vector>
#include <cstring>
#include <chrono>
#include <thread>
#include "lecture.h"
using namespace std ;

int Decodeur(char X){
		switch(X){
		case 'A': return 1;
        case 'B': return 2;
        case 'C': return 3;
        case 'D': return 4;
        case 'E': return 5;
        case 'F': return 6;
        case 'G': return 7;
        case 'H': return 8;
        case 'I': return 9;
        case 'K': return 10;
        case 'L': return 11;
        case 'M': return 12;
        case 'N': return 13;
        case 'P': return 14;
        case 'Q': return 15;
        case 'R': return 16;
        case 'S': return 17;
        case 'T': return 18;
        case 'V': return 19;
        case 'W': return 20;
        case 'X': return 21;
        case 'Y': return 22;
        case 'Z': return 23;
        case 'U': return 24;
        case '*': return 25; // Stop
        default: return 0;
	}
}

		
int smith_waterman(BlosumMatrix matrice, string prot_bdd, string prot_query, int m, int gap_open_penalty, int gap_extension_penalty) { // Retourne une liste de position dans le fichier pin des 20 protéines ressemblants le plus à la protéine de requête
	//Initialisation du score et des vecteurs colonnnes de la matrice H et E
		vector<int> H(m+1, 0); 
		vector<int> E(m+1, 0);
		int S =0;
		int score;
		for (int j = 0; j < prot_bdd.length(); j++) { //Itération sur les n colonnes
 			int H_diag_prec = 0; // Cas de base pour H[0,j]
			int F=0; // Cas de base pour F
			for (int i=1; i < m+1; i++) { //Itération sur les m lignes
				int H_gauche = H[i]; 
				E[i] = max(H_gauche - gap_open_penalty, E[i] - gap_extension_penalty) ;// Calcul de la prochaine composante de E dans le vecteur colonne
				F = max(H[i-1] - gap_open_penalty, F - gap_extension_penalty);
				score = matrice.getScore(Decodeur(prot_query[i-1]),Decodeur(prot_bdd[j]));
				H[i] = max({H_diag_prec + score, E[i], F, 0}); // Calcul de la prochaine composante de H dans le vecteur colonne
				S = max(H[i],S); // Calcul de meilleur score
				H_diag_prec = H_gauche; // Stocke en mémoire la valeur qui deviendra la valeur de H_diag_prec à la prochaine itération
			}			
		}
	return S;
}
	
