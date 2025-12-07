#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <string>
#include <unistd.h>
#include <algorithm>
#include <vector>
#include <cstring>
#include "blosum.h"
using namespace std ;


		
int smith_waterman(string blosum_path, string prot_bdd, string prot_query, int gap_open_penalty, int gap_extension_penalty) { // Retourne une liste de position dans le fichier pin des 20 protéines ressemblants le plus à la protéine de requête
		BlosumMatrix matrice;
		matrice.lecture_blosum(blosum_path);
		int m =prot_query.length();
		vector<int> H(m+1, 0);
		vector<int> E(m+1, 0);
		
		for (int j =1; j < prot_bdd.length(); j++) {
			int H_diag_prec = 0; // H[0,0]
			int F=0; // F[0,1]
			cout << "coucou"<< endl;
			for (int i=1; i <prot_query.length(); i++) {
				int H_mtn = H[i]; // Cas de base de H : H[1,0] = 0
				int new_E = max(H[i] - gap_open_penalty, E[i] - gap_extension_penalty) ;// E[i] correspond à E[1,0] et on calcule E[1,1]
				E[i+1] = new_E;
				F = max(H_diag_prec - gap_open_penalty, F - gap_extension_penalty);
				
				int score = matrice.getScore(Decodeur(prot_bdd[i]), Decodeur(prot_query[j]));
				H[i] = max({H_diag_prec + score, new_E, F, 0});
				
				H_diag_prec = H_mtn;
				cout << H_diag_prec <<endl;
				
			}
				
				
				
				
				
			
			
			
			
		}
		return 0;
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
	

