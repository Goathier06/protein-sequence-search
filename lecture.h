#include <stdlib.h>
#include <fstream>
#include <cstring>
#include <iostream>
using namespace std ;

string lect_fasta(string file_path);

char decoder(int nbr);

int lect_psq(string blosum_path, string file_path, string seq_requete, int gop, int gep);

string lect_phr(string file_path, int pos);

int lect_pin(string file_path, int indice); 

void reverse(char mot[]);

int smith_waterman(string blosum_path, string prot_bdd, string prot_query, int gap_open_penalty, int gap_extension_penalty);
