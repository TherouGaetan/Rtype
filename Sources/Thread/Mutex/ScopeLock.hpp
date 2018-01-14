#ifndef Thread_ScopeLock_h
#define Thread_ScopeLock_h

#include "IMutex.h"

namespace Thread {

    class ScopeLock {

     public:
        explicit ScopeLock(IMutex *mutex);
        ~ScopeLock();

    private:
        IMutex *mMutex;
    };

}

#endif // Thread_ScopeLock_h
