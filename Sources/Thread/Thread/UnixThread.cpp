#include <csignal>
#include "UnixThread.hpp"

namespace Thread {

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

}
