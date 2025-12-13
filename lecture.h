#include <stdlib.h>
#include <fstream>
#include <cstring>
#include <iostream>
#include <vector>
#include <map>
using namespace std ;

class BlosumMatrix{
	public:
	int matrice[28][28]={0};
    void lecture_blosum(string file_path);	
    int getScore(int a, int b);
};

int getScore(int a, int b);

int Decodeur(char X);

string lect_fasta(string file_path);

char decoder(int nbr);

vector<pair<int,int>> lect_psq(string bdd_path, string file_path, string seq_requete, int gop, int gep);

string lect_phr(string file_path, int pos);

int lect_pin(string file_path, int indice); 

void reverse(char mot[]);

int smith_waterman(BlosumMatrix matrice, string prot_bdd, string prot_query,int m, int gap_open_penalty, int gap_extension_penalty);
