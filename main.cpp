#include <iostream>
#include <vector>
#include <cstdlib>
#include "Timer.hpp"
#include "ReadyQueue.hpp"

int generateRandomPID(void){
    return rand() % 1000 + 1;
}
int generateRandomStateInt(void){
    return rand() % 3 + 1;
}
int main(){
    /*
        Currently trying to investigate a weird bug where all process objects
        have the same attributes
    */
    vector<Process*> processesVector;
    for(int i = 0; i < 5; i++){
        int randomPID = generateRandomPID();
        int randomState = generateRandomStateInt();
        std::cout << randomPID << " " << randomState << endl;
        processesVector.push_back(new Process(randomPID, randomState));
    }

    for(int i = 0; i < processesVector.size(); i++){
        processesVector[i]->printProcessInformation();
    }



}