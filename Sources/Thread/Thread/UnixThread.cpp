#include <csignal>
#include "UnixThread.hpp"

namespace Thread {

    void UnixThread::join()
    {
        pthread_join(mThread, NULL);
    }

    void UnixThread::kill()
    {
        pthread_kill(mThread, SIGINT);
    }

    int UnixThread::getIdThread() const
    {
        return 0;
    }

}
