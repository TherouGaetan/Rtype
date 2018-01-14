#include "StdCondVar.hpp"

namespace Thread {
    StdCondVar::StdCondVar(StdMutex *pMutex)
    : mMutex(pMutex)
    {
    }

    StdCondVar::~StdCondVar()
    {

    }

    void StdCondVar::signal()
    {
        mCondvar.notify_one();
    }

    void StdCondVar::wait()
    {
        std::unique_lock<std::mutex> lck(*mMutex->getMutex());
        mCondvar.wait(lck);
    }

    int StdCondVar::timedwait(int time) throw()
    {
        std::unique_lock<std::mutex> lck(*mMutex->getMutex());
        mCondvar.wait_for(lck, std::chrono::seconds(time));
        return 0;
    }
}
