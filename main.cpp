#include <iostream>
#include <vector>
#include <cstdlib>
#include "Timer.hpp"
#include "ReadyQueue.hpp"

int generateRandomPID(void){
    return rand() % 1000 + 1;
}
int generateRandomStateInt(void){
    return rand() % 2 + 1;
    //I did not include the third state so we do not have a terminated process in the ready queue
}
bool shouldReturnToReadyQueue(){
    int chance = rand() % 2;
    return chance == 1;
}
int main(){
    ReadyQueue rq;
    std::vector<double> times;
    times.push_back(1000);
    times.push_back(2000);
    times.push_back(3000);
    times.push_back(4000);
    //List of new processes
    int count = 1;
    while(count < 10){
        count++;
        Process p(generateRandomPID(), times[rand() % 4], 1);
        p.startStartToFinishTimer();
        rq.insertToReadyQueue(p);
    }

    while(true){
        Timer t;
        Process process = rq.schedule();
        process.setState(2);
        process.startProcessingTimer();
        t.start();
        while(t.elapsedMilliseconds() != process.getCPUTime()){} //Stop while loop from running
        t.stop();

        if(shouldReturnToReadyQueue()){
            process.setState(1);
            int time = rand() % 4;
            while(time == 4){
                time = rand() % 4;
            }
            process.setCPUTime(times[rand() % 4]);
            rq.insertToReadyQueue(process);
        }else{
            process.setState(3);
        }
        process.stopStartToFinishTimer();
        process.printProcessInformation();
    }
    return 0;
}