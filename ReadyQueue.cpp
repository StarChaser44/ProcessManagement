#include "ReadyQueue.hpp"

Process ReadyQueue::schedule(void){
    Process p = ReadyQueue::rq.front();
    ReadyQueue::rq.pop();
    return p;
}

void ReadyQueue::insertToReadyQueue(Process p){
    rq.push(p);
}

int ReadyQueue::getQueueSize(void){
    return ReadyQueue::rq.size();
}