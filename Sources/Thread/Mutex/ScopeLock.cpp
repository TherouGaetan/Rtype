#include "ScopeLock.hpp"

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