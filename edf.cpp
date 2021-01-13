/*
This files includes function and class definitions 
*/
// header has all the necessary declaration and the required files  
#include "edf.h"
#include "rms.h"

void rms(std::vector<std::vector<int>> tasks_vector,int n, int m) {
  std::cout<<"starting edf \n";
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
    // std::cout<<i<<"";

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
          std::cout<<i<<" task "<<tasks_vector[k][0]<<" misses \n";

        }
      }
    }
    // print_2d_vector(tasks_vector,n,m);

    for(int j = 0; j<n;j++){
      //check if a task is completed
      if(tasks_vector[j][1] ==tasks_vector[j][3]){

        //if its complete we move to the next task in the vector until one is not completes
        //go to the next tick
        if(j==n-1){
          std::cout<<i<<" no task\n";
        }
        continue;      
      }
      //if its not complete
      else{
        // check if its not the dealine
         

          // this is just normal operations which means we add a execute flag
          std::cout<<i<<" task "<<tasks_vector[j][0]<< " executes \n";
          // incrament to the completeness variable
          tasks_vector[j][3] = tasks_vector[j][3] + 1;
          // check if it completes in that cycle
          if(tasks_vector[j][1] ==tasks_vector[j][3]){

            std::cout<<i<<" task "<<tasks_vector[j][0]<< " completes \n";

          }
          break;
          
     

      }

    }


  }

  std::cout<<"\nend of the rms \n";


}

