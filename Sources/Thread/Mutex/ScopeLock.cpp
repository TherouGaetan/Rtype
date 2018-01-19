#include "ScopeLock.hpp"

namespace Thread {
    ScopeLock::ScopeLock(IMutex *pMutex) :
        mMutex(pMutex)
    {
        mMutex->lock();
    }

    ScopeLock::~ScopeLock()
    {
        mMutex->unlock();
    }
}