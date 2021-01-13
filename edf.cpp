/*
This files includes function and class definitions 
*/
// header has all the necessary declaration and the required files  
#include "edf.h"



void edf(std::vector<std::vector<int>> tasks_vector,int n, int m) {

  // we get a vector made up of only the periods
  // first make a vector with just the periods
  std::vector<int> tasks_periods;
  for(int i=0; i<n;i++){
    // the periods ate in the [.][2] postions which is why we have a two 
    tasks_periods.push_back(tasks_vector[i][2]);
  }

  // STEP 1:find the lowest common denominator
  int lcm = lowest_common_multiple(tasks_periods); // this represents the whole timeline

  std::cout<< lcm << " is the lcm \n";

  // STEP2: find the priority
  // the smaller the period the higher the priority 
  // we can just sort the task vector by the period and the smaller the index the higher the priority
  sort(tasks_vector.begin(), tasks_vector.end(),sortcol);
  // print_2d_vector(tasks_vector,n,m);
  // std::cout<<"\n";

  //  The actual algorithm 
  for(int i = 0; i<lcm;i++){
    std::cout<<i<<" ";

    //set the deadline flags to be on if a task deadline is meant to be on this tick
    for(int k = 0; k<n;k++){
      if(i==0){
        break;
      }
      // check if there is meant to be a dealine 

      if(i%tasks_vector[k][2]){
        // we set the deadline variable to zero
         tasks_vector[k][4] = 0; 

      }
      else{

        if(tasks_vector[k][1] ==tasks_vector[k][3]){
        // we want to reset the completed states
         tasks_vector[k][3] = 0;
        }
        else if(tasks_vector[k][1] !=tasks_vector[k][3]){
          // this is a misse
          std::cout<<"\ntask "<<tasks_vector[k][0]<<"misses \n";

        }
      }
    }
    print_2d_vector(tasks_vector,n,m);
    std::cout<<"\n";
    for(int j = 0; j<n;j++){
      //check if a task is completed
      if(tasks_vector[j][1] ==tasks_vector[j][3]){

        //if its complete we move to the next task in the vector until one is not completes
        //go to the next tick
        continue;      
      }
      //if its not complete
      else{
        // check if its not the dealine
         if(tasks_vector[j][4]!=1){

            // this is just normal operations which means we add a execute flag
            std::cout<<"task "<<tasks_vector[j][0]<< " executes n \n";
            // incrament to the completeness variable
            tasks_vector[j][3] = tasks_vector[j][3] + 1;
            // check if it completes in that cycle
            if(tasks_vector[j][1] ==tasks_vector[j][3]){

              std::cout<<"task "<<tasks_vector[j][0]<< " completes n \n";

            }
            break;
            

        }

      }

    }


  }

  std::cout<<"\nend of the rms \n";


}

void edf2(std::vector<int> task_periods,std::vector<int> task_priority) {
  std::cout << "rms just got executed from other file! \n";

    //step 1: find the lowest common denominator 
    // lcm(test_periods);
    auto lcm = std::accumulate(task_periods.begin(), task_periods.end(), 1, [](auto & a, auto & b) {return abs(a * b) / std::gcd(a, b);});
    std::cout<<lcm; 
    std::cout<<'\n'; 

    //step 2: find the priority 
    std::cout << "starting sorting stuff \n";
    sort(task_priority.begin(), task_priority.end());
    for (std::vector<int>::size_type i = 0; i != task_priority.size(); ++i){

        std::cout << task_priority[i] << " ";   
    }

    std::cout << '\n';
    // this depends on which has the smallest 
}

int lowest_common_multiple(std::vector<int> tasks_periods){


  // // first make a vector with just the periods
  // std::vector<int> tasks_periods;
  // for(int i=0; i<n;i++){
  //   // the periods ate in the [.][2] postions which is why we have a two 
  //   tasks_periods.push_back(task_vec[i][2]);
  // }

  auto lcm = std::accumulate(tasks_periods.begin(), tasks_periods.end(), 1, [](auto & a, auto & b) {return abs(a * b) / std::gcd(a, b);});

  return lcm;

}

// Driver function to sort the 2D vector 
// on basis of a particular column 
bool sortcol( const std::vector<int>& v1, const std::vector<int>& v2 ) { 
    

    int n = 2; // this is the thing we want to sort by 
    return v1[n] < v2[n]; 

} 

void print_2d_vector(std::vector<std::vector<int>> task_vec,int n, int m){
    std::cout << "\nprint 2_d vectors function called \n";

    // this goes through all the elements in the vector and prints them

    for(int i=0; i<n;i++){

        for(int j=0; j<m;j++ ){
            
             std::cout << task_vec[i][j] << " ";
            
        }
        std::cout<<"\n";
    }


}

void print_1d_vector(std::vector<int> task_priority){
    std::cout << "print vectors function called \n";

    // this goes through all the elements in the vector and prints them
    for (std::vector<int>::size_type i = 0; i != task_priority.size(); ++i){

        std::cout << task_priority[i] << " ";   
    }

}

