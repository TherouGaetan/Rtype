//
// Created by Gaëtan Therou on 18-01-13.
//

#include "ThreadFactory.hpp"
#ifdef TARGET_OS_WIN32
#include "Mutex/StdMutex.hpp"
#include "Condvar/StdCondVar.hpp"
#else
#include "Mutex/UnixMutex.hpp"
#include "Condvar/UnixCondVar.hpp"
#endif

namespace Thread {

    ThreadFactory ThreadFactory::mInstance = ThreadFactory();

    ThreadFactory::ThreadFactory() {

    }

    ThreadFactory &ThreadFactory::getInstance() {
        return mInstance;
    }

    IMutex *ThreadFactory::makeMutex() const {
#ifdef TARGET_OS_WIN32
        return new StdMutex();
#else
        return new UnixMutex();
#endif
    }

    ICondVar *ThreadFactory::makeCondVar() const {
#ifdef TARGET_OS_WIN32
        return new StdCondVar(dynamic_cast<StdMutex*>(makeMutex()));
#else
        return new UnixCondVar(dynamic_cast<UnixMutex*>(makeMutex()));
#endif
    }

}