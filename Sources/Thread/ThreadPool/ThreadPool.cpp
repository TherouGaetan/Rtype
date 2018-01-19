#include "ThreadPool.hh"
#include "../ThreadFactory.hpp"

namespace Thread 
{
	template<class T, class U>
	ThreadPool<T, U>::ThreadPool(unsigned int pNbThread)
	{
		mCondQueue = ThreadFactory::getInstance().makeCondVar();

		for (unsigned char i = 0; i < pNbThread; i++)
		{
			U *job = new U(mCondQueue, &mQueue);

			IThread *thread = ThreadFactory::getInstance().makeThread(&DoTheJob<T>::run, job, &mQueue);

			std::pair<U, IThread *> pair(job, thread);
			mThreads.push_back(pair);
		}
	}

	template <class T, class U>
	ThreadPool<T, U>::~ThreadPool()
	{
		for (unsigned int i = 0; i < mThreads.size(); i++)
		{
			mThreads.at(i).first->stop();
			mThreads.at(i).second->join();
		}
		for (unsigned int i = 0; i < mThreads.size(); i++) {
			mThreads.at(i).second->kill();
			delete mThreads.at(i).first;
			delete mThreads.at(i).second;
		}
		
		mThreads.erase(mThreads.begin(), mThreads.end());

		delete mCondQueue;
	}

	template <class T, class U>
	unsigned long ThreadPool<T, U>::pushInQueue(T *pElem)
	{
		mQueue.push_back(pElem);
		mCondQueue->signal();
		return mQueue.size();
	}

}
