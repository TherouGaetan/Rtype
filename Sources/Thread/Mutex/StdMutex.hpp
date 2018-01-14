#ifndef Thread_StdMutex_h
#define Thread_StdMutex_h

#include <mutex>
#include "IMutex.h"

namespace Thread {

    class StdMutex: public IMutex
    {
    public:
        StdMutex();
        virtual ~StdMutex();

    public:
        void lock() override;
        void unlock() override;
        void try_lock() override;
        std::mutex *getMutex() const;

    private:
        std::mutex  *mMutex;
    };
}

#endif // Thread_StdMutex_h
