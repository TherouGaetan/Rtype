#ifndef Thread_StdCondVar_h
#define Thread_StdCondVar_h

#include <condition_variable>
#include <mutex>
#include <chrono>
#include "ICondVar.h"
#include "../Mutex/StdMutex.hpp"

namespace Thread {

    class StdCondVar: public ICondVar
    {
    public:
        StdCondVar();
        explicit StdCondVar(StdMutex *pMutex);
        virtual ~StdCondVar();

    public:
        void signal() override;
        void wait() override;
        int timedwait(int pTime) throw() override;

     public:
        StdMutex                *mMutex;
        std::condition_variable mCondvar;
    };

} /* End of namespace Thread */

#endif // Thread_StdCondVar_h
