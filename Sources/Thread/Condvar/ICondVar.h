#ifndef Thread_ICondVar_h
#define Thread_ICondVar_h

#include "../Mutex/IMutex.h"

namespace Thread {

    class ICondVar {
    public:
        virtual ~ICondVar() {}

     public:
        virtual void signal()  = 0;
        virtual void wait()  = 0;
        virtual int timedwait(int pTime) throw() = 0;
    };

} /* End of namespace Thread */

#endif // Thread_ICondVar_h
