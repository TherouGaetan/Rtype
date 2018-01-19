#include "DoTheJob.h"

namespace Thread {

	template<typename T>
	DoTheJob<T>::DoTheJob(Thread::ICondVar *pCondQueue, std::list<T *> *pQueue) :
			AConsumer(pCondQueue) {
	}

	template<typename T>
	DoTheJob<T>::~DoTheJob() {
	}

	template<typename T>
	void DoTheJob<T>::run() {
		while (mRun) {
			if (mQueue->empty())
				mCondQueue->wait();
			else {
				T *job = mQueue->front();
				mQueue->pop_front();
				if (!mQueue->empty())
					mCondQueue->signal();
			}
		}
	}

}