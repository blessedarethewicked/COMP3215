/*
This files includes function and class definitions 
*/
// header has all the necessary declaration and the required files  
#include "edf.h"
#include "rms.h"

std::vector<std::string> edf(std::vector<std::vector<int>> tasks_vector,int n, int m) {
  std::cout<<"starting edf \n";

  // we need to set up the output vector which we are going to be writing to the output file
  std::vector<std::string> output_vector;
  std::string output_string;
  int deadline_misses=0;
   output_vector.push_back("------------------------");
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

  // STEP2: the algoritms is baded on the easiest dealine 
  // each task has a subscript which denotes the number of times it has completed
  //  once a task completes we change its dealine and resort the so the task with the earlist deadline
  //  is always the fist

  //  The actual algorithm 
  for(int i = 0; i<lcm;i++){
    // std::cout<<i<<"";

    //set the deadline flags to be on if a task deadline is meant to be on this tick
    for(int k = 0; k<n;k++){
      //check if it is the first cycle 
      if(i==0){
        // set the dealines which in this case are the fist piriods
        tasks_vector[k][4] = tasks_vector[k][4] + tasks_vector[k][2]; 
      }else{

        // check if there is meant to be a dealine 

        if(i%tasks_vector[k][2]){
        // we set the deadline variable to zero
        // tasks_vector[k][4] = 0; 
        // check if we are past the deadline and if so we missed
        if(i>tasks_vector[k][4]){
          std::cout<<i<<" task "<<tasks_vector[k][0]<<" misses \n";
          deadline_misses++;
          // write it to output vector
          output_string = std::to_string(i) + " task " + std::to_string(tasks_vector[k][0]) + " misses";
          output_vector.push_back(output_string);

        }

        }
        else{

          if(tasks_vector[k][1] ==tasks_vector[k][3]){
          // we want to reset the completed states
          tasks_vector[k][3] = 0;
          }
          else if(tasks_vector[k][1] !=tasks_vector[k][3]){
          // this is a miss
          //print it out to screen 
          std::cout<<i<<" task "<<tasks_vector[k][0]<<" misses \n";
          deadline_misses++;
          // write it to output vector
          output_string = std::to_string(i) + " task " + std::to_string(tasks_vector[k][0]) + " misses";
          output_vector.push_back(output_string);


          }
        }
      }
    }
    // print_2d_vector(tasks_vector,n,m);
    //  this sorts the task based on the dealine
    // the task with the ealist deadline comes first 
    sort(tasks_vector.begin(), tasks_vector.end(),sortcoledf);
    for(int j = 0; j<n;j++){
      //check if a task is completed
      if(tasks_vector[j][1] ==tasks_vector[j][3]){

        //if its complete we move to the next task in the vector until one is not completes
        //go to the next tick
        if(j==n-1){
          std::cout<<i<<" no task\n";
          output_string =  "no task";
          output_vector.push_back(output_string);
        }
        continue;      
      }
      //if its not complete
      else{
        // check if its not the dealine
         

          // this is just normal operations which means we add a execute flag
          std::cout<<i<<" task "<<tasks_vector[j][0]<< " executes \n";
          output_string = std::to_string(i) + " task " + std::to_string(tasks_vector[j][0]) + " executes";
          output_vector.push_back(output_string);
          // incrament to the completeness variable
          tasks_vector[j][3] = tasks_vector[j][3] + 1;
          // check if it completes in that cycle
          if(tasks_vector[j][1] ==tasks_vector[j][3]){

            std::cout<<i<<" task "<<tasks_vector[j][0]<< " completes \n";
            output_string = std::to_string(i) + " task " + std::to_string(tasks_vector[j][0]) + " completes";
            output_vector.push_back(output_string);
            // when a task completes we change its dealine 
            tasks_vector[j][4] = tasks_vector[j][4] + tasks_vector[j][2];

          }
          break;
          
     

      }

    }


  }
  output_vector.push_back("------------------------");
  output_string = std::to_string(deadline_misses) + " deadline misses in total \n";
  output_vector.push_back(output_string);
  std::cout<<"\nend of the edf \n";
  return output_vector;


}

// Driver function to sort the 2D vector 
// on basis the dealine
bool sortcoledf( const std::vector<int>& v1, const std::vector<int>& v2 ) { 
    

    int n = 4; // this is the thing we want to sort by 
    return v1[n] < v2[n]; 

} 

