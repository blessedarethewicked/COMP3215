#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

// this fuction houses the rms algorithm 
void rms(std::vector<std::vector<int>> tasks_vector,int n, int m);

//this is not a used function. i only had it for testing purposes
void rms2(std::vector<int> task_periods,std::vector<int> task_priority);

// tis fuction finds the lowest common multple for a list o numbers
int lowest_common_multiple(std::vector<int> tasks_periods);

// Driver function to sort the 2D vector 
// on basis of a particular column 
bool sortcol( const std::vector<int>& v1, const std::vector<int>& v2 );

// This function allows me to print out the vectors that i am using
void print_2d_vector(std::vector<std::vector<int>> task_vec,int n, int m);

//this jst prints one vector
void print_1d_vector(std::vector<int> task_priority);