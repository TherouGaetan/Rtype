#ifndef Thread_UnixMutex_h
#define Thread_UnixMutex_h

#include <pthread.h>
#include "IMutex.h"

namespace Thread {

    class UnixMutex: public IMutex
    {
     public:
        UnixMutex();
        virtual ~UnixMutex();

    public:
        void lock() override;
        void unlock() override;
        void try_lock() override;
        pthread_mutex_t *getMutex() const;

     private:
        pthread_mutex_t	mMutex;
    };

}

#endif // Thread_UnixMutex_h
