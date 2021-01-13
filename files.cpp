/*
This files includes function and class definitions 
*/
// header has all the necessary declaration and the required files  
#include "files.h"


// This function makes a vector of strings which represent the output and prints them all out to a output file. 
void write_to_file(std::string fname,std::vector<std::string> output_vector){

    // prints to consol that the function has been called and tells us which file its  going to write to 
    std::cout<<"write to file '" + fname + "' function called \n"; 

    //opens the file 
    std::ofstream myfile (fname);
    //test condition that the file is open
    if (myfile.is_open()){
        // iterate through the output vector and writes all the outputs to the output file
        for (std::vector<std::string>::iterator i=output_vector.begin(); i != output_vector.end(); ++i){
        //writes the line to the screen 
        std::cout<<*i;
        std::cout<< '\n';

        //writes the line to the output file
        myfile <<*i;
        myfile << '\n';
        } 
        
        //closes the file when i am done writing 
        myfile.close();
    }

    // if we fail to open the file we write it to screen
    else{
    std::cout<< "Unable to open file";

    } 

}
