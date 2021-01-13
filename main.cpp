/*
This is the code that i have for the coursework
*/

// standand libraries
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <array>
#include <numeric>

// my header files
#include "rms.h"
// rms(); //calls the rms fuction
#include "edf.h"
// edf(); //calls the edf fuction
#include "files.h"
// write_to_file(file_name, output);(); //calls the edf fuction

std::vector<std::string> output; // this is where i save what i am going to write out into teh output file
std::vector<int> test_priority_1d; // test vector of perods 
int n = 5; // this is the number of tasks this is the rows [x][.]
int m = 3; // this is the number of parameters that we have at this point this is the colum [.][x] 
std::vector<std::vector<int>> test_priority_2d( n , std::vector<int> (m, 0)); // test vector of perods 


int main() {
    std::cout << "starting vector test \n";

    std::cout << "ending vector test \n";
    return 0;
}