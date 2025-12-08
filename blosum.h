#include <vector>
#include <string>
#include <map>
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std ;

class BlosumMatrix{
	public:
	int matrice[28][28]={0};
    void lecture_blosum(string file_path);	
    int getScore(int a, int b);
};

int getScore(int a, int b);

inline int Decodeur(char X){
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
