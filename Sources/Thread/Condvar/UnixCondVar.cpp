#include "UnixCondVar.h"

namespace Thread {

    UnixCondVar::UnixCondVar(UnixMutex *mutex) :
        mMutex(mutex)
    {
        pthread_cond_init(&mCondvar, NULL);
    }

    UnixCondVar::~UnixCondVar()
    {
        pthread_cond_destroy(&mCondvar);
    }

    void UnixCondVar::signal()
    {
        pthread_cond_signal(&mCondvar);
    }

    void UnixCondVar::wait()
    {
        ScopeLock lock(mMutex);

        pthread_cond_wait(&mCondvar, mMutex->getMutex());
    }

    int UnixCondVar::timedwait(int pMilli)
    {
        struct timespec time;
        ScopeLock lock(mMutex);
        pthread_mutex_t *mut = mMutex->getMutex();

        if ((clock_gettime(CLOCK_REALTIME, &time)) == -1)
          throw EncapsException("Fail clock getTime", "CondVar Error");
        //time.tv_sec += 0;
        time.tv_nsec += (pMilli * 1000000);
        return pthread_cond_timedwait(&mCondvar, mut, &time);
    }
}
