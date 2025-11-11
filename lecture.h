#include <stdlib.h>
#include <fstream>
#include <cstring>
#include <iostream>
using namespace std ;

string lect_fasta(string file_path);

char decoder(int nbr);

int lect_psq(string file_path, string seq_requete);

string lect_phr(string file_path, int pos);

int lect_pin(string file_path, int indice); 

void reverse(char mot[]);
