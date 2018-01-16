#include "StdMutex.hpp"

namespace Thread {

    StdMutex::StdMutex()
    {
        mMutex = new std::mutex();
    }

    StdMutex::~StdMutex()
    {
        delete mMutex;
    }

    void StdMutex::lock()
    {
        mMutex->lock();
    }

    void StdMutex::unlock()
    {
        mMutex->unlock();
    }

    void StdMutex::try_lock()
    {
        mMutex->try_lock();
    }

    std::mutex *StdMutex::getMutex() const
    {
        return mMutex;
    }

}