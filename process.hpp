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
        Process(int id, int currentState);
        void setState(int newProcessState);
        void setPID(int id);
        State getState(void);
        int getPID(void);
        void printProcessInformation(void);
        void startStartToFinishTimer(void);
        void stopStartToFinishTimer(void);
        void startProcessingTimer(void);
        void stopProcessingTimer(void);
        void setCPUTime(void);
};