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

// this function takes the task from the txt and makes then into the form of a vector
std::vector<std::vector<int>> file_to_vector(std::string fname,int m,int &n){
    // 
    std::ifstream myfile ("testcase2.txt");
    std::string line;
    int linetracker = 0;
    std::vector<std::vector<int>> test_priority_2d;
    if (myfile.is_open()){
        while (getline(myfile,line) ){

            std::istringstream iss(line);
            std::vector<std::string> results((std::istream_iterator<std::string>(iss)),std::istream_iterator<std::string>());
            if(linetracker==0){
                n = std::stoi(results[1]);
               std::vector<std::vector<int>> temp( n , std::vector<int> (m, 0)); // test vector of perods 
               test_priority_2d = temp;
            }
            else{
                // first split the string into words 
                

                test_priority_2d[linetracker-1][0] = (int)results[0][4]-48; //we only need to look at the fifth character 
                                                                          //because the longest testcase has 6 tasks
                test_priority_2d[linetracker-1][1] = std::stoi(results[1]);
                test_priority_2d[linetracker-1][2] = std::stoi(results[2]);

            }
        linetracker++;
        }
        myfile.close();
        
    }
    else std::cout << "Unable to open file"; 
    linetracker = 0;

    return test_priority_2d;


}