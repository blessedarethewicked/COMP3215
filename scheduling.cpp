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

int n; // this is the number of tasks this is the rows [x][.]
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

    std::string file_name;
    std::string output_name;
    file_name = "testcase1";

    // get the name of the file
    std::cout<<"What is the file name (defult is testcase1 ) \n";
    std::cin>> file_name;
    std::cout<<file_name<<"\n";
    // reads in the vector from the file
    test_priority_2d = file_to_vector(file_name,m,n);
    print_2d_vector(test_priority_2d,n,m);

    // schedule the edf
    output = edf(test_priority_2d,n,m);
    output_name = file_name + "edf.txt";
    write_to_file(output_name, output);
    
    // schedule the rms
    output = rms(test_priority_2d,n,m);
    output_name = file_name + "rms.txt";
    write_to_file(output_name, output);

    std::cout << "ending scheduling \n";
    return 0;
}