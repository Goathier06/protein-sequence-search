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
#include "blosum.h"
using namespace std ;


		
int smith_waterman(string blosum_path, string prot_bdd, string prot_query, int gap_open_penalty, int gap_extension_penalty) { // Retourne une liste de position dans le fichier pin des 20 protéines ressemblants le plus à la protéine de requête
		BlosumMatrix matrice;
		matrice.lecture_blosum(blosum_path);
		int m =prot_query.length();
		int score;
		vector<int> H(m+1, 0); 
		vector<int> E(m+1, 0);
		int S =0;
		for (int j = 0; j < prot_bdd.length(); j++) {
			//cout << "NOUVELLE COLONNE" << endl;
 			int H_diag_prec = 0; // Ce H et F sont nos cas de base se trouvant tout en haut dans le graphe de dépendance, 
			int F=0; // donc à chaque nouvelle colonne, ils sont égaux à 0
			for (int i=1; i < m+1; i++) {
				int H_gauche = H[i];
				int new_E = max(H_gauche - gap_open_penalty, E[i] - gap_extension_penalty) ;// E[i] correspond à E[1,0] et on calcule E[1,1]
				E[i] = new_E;
				F = max(H[i-1] - gap_open_penalty, F - gap_extension_penalty);
				score = matrice.getScore(Decodeur(prot_query[i-1]),Decodeur(prot_bdd[j]));
				/*
				if (i > m -3) {
				cout << "score:"<<score << endl;
				cout << prot_query[i] << endl;
				cout << prot_bdd[j] << endl;
				cout << "h final : " << H[m] << endl;
				sleep(1);
			}
				//sleep(0.1);
				*/
				H[i] = max({H_diag_prec + score, E[i], F, 0});
				/*
				cout << "H diag prec" << H_diag_prec + score << endl;
				cout << "E" << E[i]<< endl;
				cout << "F" << F << endl;
				cout << "H[i]" << H[i] << endl;
				*/
				
				S = max(H[i],S);
				
				H_diag_prec = H_gauche;
				//cout << H_diag_prec <<endl;
				//cout << score << endl;
			}			
		}
		//cout << "baka:"<< S << endl;
		return S;
	}
		
		
		
		
/*
		if (indice1 == 0 && indice2 ==0) {
			H[indice1] = 0;
			}
		else if (indice1 ==0) {
				F = 0;
			}
		}
		else if (indice2 == 0) {
				E[indice1] = 0;
				}
			}
		else {
		E[indice1,indice2] = max (smith_waterman(prot_bdd, prot_query, gap_open_penalty, gap_extension_penalty, indice1, indice2-1) - gap_open_penalty, E[indice1, indice2-1] - gap_extension_penalty);
		F[indice1,indice2] = max (smith_waterman(prot_bdd, prot_query, gap_open_penalty, gap_extension_penalty, indice1-1, indice2) - gap_open_penalty, F[indice1-1, indice2] - gap_extension_penalty);
		H[indice1] = smith_waterman(prot_bdd, prot_query, gap_open_penalty, gap_extension_penalty, indice1-1, H, E, F) + matrice.getScore( 
		
		
		max((smith_waterman(prot_bdd, prot_query, gap_open_penalty, gap_extension_penalty, indice1-1, indice2-1 + matrice.getScore(Decodeur(prot_query[indice1])), Decodeur(prot_bdd[indice2])), E[indice1][indice2], F[indice1][indice2]);
		return H[indice1];

			}
		}	
*/		
