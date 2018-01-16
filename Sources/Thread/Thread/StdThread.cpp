//
// Created by Gaëtan Therou on 18-01-13.
//

#include "StdThread.hpp"

namespace Thread {
    void StdThread::join()
    {
        if (mThread.joinable())
            mThread.join();
    }

    void StdThread::kill()
    {
        mThread.detach();
    }

    int StdThread::getIdThread() const
    {
        return 0;
    }
}