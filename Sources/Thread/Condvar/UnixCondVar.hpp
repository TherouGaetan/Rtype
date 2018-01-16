#ifndef Thread_UnixCondVar_h
#define Thread_UnixCondVar_h

#include <pthread.h>

#include "../Condvar/ICondVar.h"
#include "../Mutex/IMutex.h"
#include "../Mutex/ScopeLock.hpp"
#include "../Mutex/UnixMutex.hpp"

namespace Thread {
    class UnixCondVar: public ICondVar
    {
    public:
        explicit UnixCondVar(UnixMutex *mutex);
        virtual ~UnixCondVar();

    public:
        void signal() override;
        void wait() override;
        int timedwait(int time) throw() override ;

     public:
        UnixMutex       *mMutex;
        pthread_cond_t  mCondvar;
    };
}

#endif // Thread_UnixCondVar_h
