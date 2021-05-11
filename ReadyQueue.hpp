#include <queue>
#include "process.hpp"
using namespace std;
class ReadyQueue {
    public:
    queue<Process> rq;
    Process schedule(void);
    void insertToReadyQueue(Process p);
    int getQueueSize(void);
};