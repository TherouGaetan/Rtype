#ifndef Thread_UnixCondVar_h
#define Thread_UnixCondVar_h

#include <pthread.h>

#include "../Condvar/ICondVar.h"
#include "../Mutex/IMutex.h"
#include "../Mutex/ScopeLock.h"
#include "../Mutex/UnixMutex.h"

namespace Thread {
    class UnixCondVar: public ICondVar
    {
    public:
        UnixCondVar(UnixMutex *mutex);
        ~UnixCondVar();

    public:
        void signal() override;
        void wait() override;
        int timedwait(int time) override;

     public:
        UnixMutex       *mMutex;
        pthread_cond_t  mCondvar;
    };
}

#endif // Thread_UnixCondVar_h
