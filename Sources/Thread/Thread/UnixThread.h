#ifndef Thread_UnixThread_h
#define Thread_UnixThread_h

#include <pthread.h>
#include "IThread.h"

namespace Thread {

class UnixThread: public IThread
{
 public:
    template <class T, class ...Args>
    UnixThread(T &func, Args &...params);
    ~UnixThread();

public:
    void join() override;
    void kill() override;
    int getIdThread() const override;

 private:
    pthread_t _thread;
};

} /* End of namespace Thread */

#endif // Thread_UnixThread_h
