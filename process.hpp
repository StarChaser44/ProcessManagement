
class Process 
{
    public:
        enum State 
        {
        ready_process =  1,
        running_process,
        terminated_process
        };

    
        Process();
        Process(int id, double seconds, int currentState);
        void setState(int newProcessState);
        void setRandomPID();
        State getState(void);
        int getPID(void);
        double getCPUTime(void);
        void printProcessInformation(void);
        void startStartToFinishTimer(void);
        void stopStartToFinishTimer(void);
        void startProcessingTimer(void);
        void stopProcessingTimer(void);
        void setCPUTime(double seconds);
};