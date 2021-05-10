#include <queue>
#include "process.hpp"
using namespace std;
class ReadyQueue {
    queue<Process> rq;
    Process schedule(void);
    void insertToReadyQueue(Process p);
};