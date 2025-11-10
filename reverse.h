#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <unistd.h>
#include <cstring>
using namespace std ;
void reverse(char mot[]) {
    char inter = mot[0];
        mot[0] = mot[3];
        mot[3] = inter;
        inter = mot[1];
        mot[1] = mot[2];
        mot[2] = inter;
    }







