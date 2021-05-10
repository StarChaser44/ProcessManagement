#include "Timer.hpp"
#include "process.hpp"
#include <iostream>
#include <stdlib.h>
#include <string>

unsigned int pid;

Process::State state;

Timer startToFinishTimer;
Timer processingTimer;
unsigned int cpuTime;

Process::Process(){}

Process::Process(int id, int currentState){
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

void Process::setPID(int id){
    pid = id;
}

Process::State Process::getState(void){
    return state;
}

int Process::getPID(void){
    return pid;
}

void Process::startStartToFinishTimer(void){
    startToFinishTimer.start();
}

void Process::stopStartToFinishTimer(void){
    startToFinishTimer.stop();
}

void Process::startProcessingTimer(void){
    processingTimer.start();
}

void Process::stopProcessingTimer(void){
    processingTimer.stop();
}

void Process::setCPUTime(void){
    cpuTime = rand() % 10; 
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
    std::cout << "[PID: " << pid << ", CPU Time: " << cpuTime << " State: " << currentState << "]" << std::endl;
}