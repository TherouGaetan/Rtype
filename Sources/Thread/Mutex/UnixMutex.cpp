#include "UnixMutex.h"

namespace Thread {

    UnixMutex::UnixMutex()
    {
        pthread_mutex_init(&mMutex, NULL);
    }

    UnixMutex::~UnixMutex()
    {
        pthread_mutex_destroy(&mMutex);
    }

    void UnixMutex::lock()
    {
        pthread_mutex_lock(&mMutex);
    }

    void UnixMutex::unlock()
    {
        pthread_mutex_unlock(&mMutex);
    }

    void UnixMutex::try_lock()
    {
        pthread_mutex_trylock(&mMutex);
    }

    pthread_mutex_t *UnixMutex::getMutex() const {
        return &mMutex;
    }

}
