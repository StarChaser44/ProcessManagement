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
    Process p1 (generateRandomPID(), 1000, 1);
    rq.insertToReadyQueue(p1);
    p1.startStartToFinishTimer();
    Process p2 (generateRandomPID(), 2000, 1);
    rq.insertToReadyQueue(p2);
    p2.startStartToFinishTimer();
    Process p3 (generateRandomPID(), 3000, 1);
    rq.insertToReadyQueue(p3);
    p3.startStartToFinishTimer();
    Process p4 (generateRandomPID(), 7000, 1);
    rq.insertToReadyQueue(p4);
    p4.startStartToFinishTimer();
    Process p5 (generateRandomPID(), 1000, 1);
    rq.insertToReadyQueue(p5);
    p5.startStartToFinishTimer();

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
            int newCPUTimeIndex = rand() % 4;
            while(newCPUTimeIndex != 4){
                newCPUTimeIndex = rand() % 4;
            }
            process.setCPUTime(rand() % 4);
            rq.insertToReadyQueue(process);
        }else{
            process.setState(3);
        }
        process.stopStartToFinishTimer();
        process.printProcessInformation();
    }

}