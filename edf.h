#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

// this fuction houses the rms algorithm 
void edf(std::vector<std::vector<int>> tasks_vector,int n, int m);
// sorts the tasks based on the 
bool sortcoledf( const std::vector<int>& v1, const std::vector<int>& v2 );