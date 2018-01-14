#include "ScopeLock.h"

namespace Thread {
    ScopeLock::ScopeLock(IMutex *mutex) :
        mMutex(mutex)
    {
        mMutex->lock();
    }

    ScopeLock::~ScopeLock()
    {
        mMutex->unlock();
    }
}