#include "UnixThread.h"

namespace Thread {

template <class T, class ...Args>
UnixThread::UnixThread(T &func, Args &...params)
{
    pthread_create(&_thread, NULL, func, params);
}

UnixThread::~UnixThread()
{
}

void UnixThread::join()
{
    pthread_join(_thread, NULL);
}

void UnixThread::kill()
{
    pthread_kill(_thread, SIGINT);
}

int UnixThread::getIdThread() const
{
    return 0;
}

} /* End of namespace Thread */
