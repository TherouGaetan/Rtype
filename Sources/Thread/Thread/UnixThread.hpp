#ifndef Thread_UnixThread_h
#define Thread_UnixThread_h

#include <pthread.h>
#include "IThread.h"

namespace Thread {

    class UnixThread: public IThread
    {
     public:
        template <class T, class ...Args>
        explicit UnixThread(T &&func, Args &&...params) {
            pthread_create(&_thread, NULL, func, params...);
        };
        ~UnixThread() {};

    public:
        void join() override;
        void kill() override;
        int getIdThread() const override;

     private:
        pthread_t _thread;
    };

} /* End of namespace Thread */

#endif // Thread_UnixThread_h
