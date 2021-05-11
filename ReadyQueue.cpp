#include "ReadyQueue.hpp"

Process ReadyQueue::schedule(void){
    return ReadyQueue::rq.front();
}

void ReadyQueue::insertToReadyQueue(Process p){
    rq.push(p);
}

int ReadyQueue::getQueueSize(void){
    return ReadyQueue::rq.size();
}