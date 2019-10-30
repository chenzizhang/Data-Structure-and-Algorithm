#include <iostream>
#include "OfficeHour.h"
/*
Given the current Office Hour queue and the currently on-duty staffers, return
how long the nth student will need to wait before a Staffer can reach them
Return -1 if there are no staff available to help the nth student

@param queue A queue containing the students currently waiting for help
@param onDutyStaff  A vector of Staffers currently on duty
@param nthStudent   The student for whom we are calculating a wait time
@return             How many minutes the nth student will have to wait before getting help
*/
int waitTime(queue<Student> queue, vector<Staffer> onDutyStaff, int nthStudent) {
    // Your code here!
    int time = 0;
    vector<int> AnswerTime;
    bool EnergyStaff;
    int count = 0;

    //1. create answer time table based on staff number
    for(unsigned i = 0; i < onDutyStaff.size(); i++){
      AnswerTime.push_back(0);
      std::cout << "AT:  " << i << std::endl;
    }

    //2. loop untile student n
    while(count < nthStudent){

      //2.2 check if there is an energitic staff
      EnergyStaff = false;
      for(auto & staff: onDutyStaff){
        if(staff.getEnergyLevel() > 0){
          EnergyStaff = true;
          break;
        }
      }
      // std::cout << "line:  " << EnergyStaff << std::endl;
      //2.3.1 if there is no staff available
      if(EnergyStaff == false) {return -1;}
      //2.3.2 if the is staff avaiable
      else{
        //2.3.2.(1)find smallest waiting time needed
        int min_time = 2147483647;
        int index = 0;
        int min_index = -1;
        while(index < int(AnswerTime.size())){
          std::cout << "line1: " << index << " ; "<< onDutyStaff[index].getEnergyLevel() << std::endl;
          if(onDutyStaff[index].getEnergyLevel() > 0){
            std::cout << "line2: " << index << " ; "<< onDutyStaff[index].getEnergyLevel() << std::endl;
            if(AnswerTime[index] == 0 ){
              min_time = 0;
              min_index = index;
              break;
            }
            else{
              if(AnswerTime[index] < min_time){
                min_index = index;
                min_time = AnswerTime[index];
              }
            }
          }
          index++;
        }
        // std::cout << "line min_index: " << index << " ; "<< min_index << std::endl;

        //2.3.2.(2) not found, no sfaffer available
        if(min_index == -1){ return -1;}
        else{
          //2.3.2.(2.1) found and don't need to wait, assign AnswerTime
          if(min_time == 0){
            Student tmp = queue.front();
            queue.pop();
            count ++;

            AnswerTime[min_index] = onDutyStaff[min_index].answerQuestion(tmp.getQuestionType(), tmp.getTimeNeeded());
          }
          //2.3.2.(2.2) found and need to wait, add on wait time and deduct wait time
          else{
            time += min_time;

            for(auto & Ans: AnswerTime){
              Ans = std::max(0, Ans - min_time);
            }

          }
        }
      }


    }
    return time;

}
