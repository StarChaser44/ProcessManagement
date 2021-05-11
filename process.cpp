#include "Timer.hpp"
#include "process.hpp"
#include <iostream>
#include <stdlib.h>
#include <string>


Process::State state;

int pid;
Timer startToFinishTimer;
Timer processingTimer;
double cpuTime = 0;
double timeSpentFromRQToTerm = 0;

Process::Process(){}

Process::Process(int id, double seconds, int currentState){
    pid = id;
    switch(currentState){
        case 1:
            state = ready_process;
            break;
        case 2:
            state = running_process;
            break;
        case 3:
            state = terminated_process;
            break;
        default:
            std::cerr << "Invalid state" << std::endl;
    }
    cpuTime = seconds;
}

void Process::setState(int new_process_state){
    switch(new_process_state){
        case 1:
            state = ready_process;
            break;
        case 2:
            state = running_process;
            break;
        case 3:
            state = terminated_process;
            break;
        default:
            std::cerr << "Invalid state" << std::endl;
    }
}

void Process::setRandomPID(){
    pid = rand() % 1000 + 1;
}

Process::State Process::getState(void){
    return state;
}

int Process::getPID(void){
    return pid;
}

double Process::getCPUTime(void){
    return cpuTime;
}

void Process::startStartToFinishTimer(void){
    startToFinishTimer.start();
}

void Process::stopStartToFinishTimer(void){
    timeSpentFromRQToTerm = startToFinishTimer.elapsedMilliseconds();
    startToFinishTimer.stop();
}

void Process::startProcessingTimer(void){
    processingTimer.start();
}

void Process::stopProcessingTimer(void){
    processingTimer.stop();
}

void Process::setCPUTime(double seconds){
    cpuTime = seconds; 
}

void Process::printProcessInformation(void){
    std::string currentState = "";
    if(state == Process::ready_process){
        currentState = "Ready";
    }else if(state == Process::running_process){
        currentState = "Running";
    }else if(state == Process::terminated_process){
        currentState = "Terminated";
    }
    std::cout << "[PID: " << pid << ", CPU Time: " << cpuTime << ", State: " << currentState << ", Time spent from creation to exiting CPU: " << timeSpentFromRQToTerm << "]"<< std::endl;
}