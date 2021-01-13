#include <iostream>
#include <sstream>
#include <iterator>
#include <fstream>
#include <string>
#include <vector>


// this file writes whatever is in output_vector into a file with the name in fname
void write_to_file(std::string fname,std::vector<std::string> output_vector);

// this function takes the task from the txt and makes then into the form of a vector
std::vector<std::vector<int>> file_to_vector(std::string fname,int m);