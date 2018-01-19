//
// Created by Gaëtan Therou on 18-01-13.
//

#ifndef RTYPE_THREADFACTORY_HPP
#define RTYPE_THREADFACTORY_HPP

#include <tuple>
#include "Mutex/IMutex.h"
#include "Condvar/ICondVar.h"
#include "Thread/IThread.h"
#ifdef TARGET_OS_WIN32
#include "Thread/StdThread.hpp"
#else
#include "Thread/UnixThread.hpp"
#endif

namespace Thread {
    class ThreadFactory {
    private:
        explicit ThreadFactory();

    public:
        virtual ~ThreadFactory() {};

    public:
        static ThreadFactory   &getInstance();

    public:
        IMutex      *makeMutex() const;
        ICondVar    *makeCondVar() const;
        template <class T, class ...Args>
        IThread     *makeThread(T &&func, Args &&...params) const {
#ifdef TARGET_OS_WIN32
            return new StdThread(func, params...);
#else
            return new UnixThread(func, params...);
#endif
        };

    private:
        static ThreadFactory    mInstance;
    };
}

#endif //RTYPE_THREADFACTORY_HPP
