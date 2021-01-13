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

int n = 3; // this is the number of tasks this is the rows [x][.]
int m = 5; // this is the number of parameters that we have at this point this is the colum [.][x] 

std::vector<std::string> output; // this is where i save what i am going to write out into teh output file
std::vector<int> test_periods; // test vector of perods 
std::vector<int> test_priority; // test vector of perods 
std::vector<std::vector<int>> test_priority_2d( n , std::vector<int> (m, 0)); // test vector of perods 


std::string one; //declaration of the file name variable
std::string two; //declaration of the file name variable
std::string three; //declaration of the file name variable


int main() {
    std::cout << "starting scheduling \n";

    test_priority_2d[0][0]= 1;
    test_priority_2d[0][1]= 2;
    test_priority_2d[0][2]= 10;
    test_priority_2d[1][0]= 2;
    test_priority_2d[1][1]= 1;
    test_priority_2d[1][2]= 4;
    test_priority_2d[2][0]= 3;
    test_priority_2d[2][1]= 2;
    test_priority_2d[2][2]= 5;

    edf(test_priority_2d,n,m);


    //this is not importent rn
    /*
    std::string file_name; //declaration of the file name variable
    file_name = "output.txt"; // we set the file name variable 

    std::string line; //declaration of the file name variable
    line = "this is my new file"; // we set the file name variable 

    one = "line one";
    two = "line two";
    three = "line three";

    output.push_back(one); // this adds an element to the end of the array
    output.push_back(two);
    output.push_back(three);

    write_to_file(file_name, output); // call the write to file fuction
    */

    std::cout << "ending scheduling \n";
    return 0;
}