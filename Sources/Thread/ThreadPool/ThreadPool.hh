#ifndef THREADPOOL_HH
#define THREADPOOL_HH

#include <list>
#include <vector>
#include <utility>

#include "DoTheJob.h"
#include "../Thread/IThread.h"

#ifdef __linux__
#include "UnixThread.h"
#include "UnixCondVar.h"
#else
#include "../Thread/StdThread.hpp"
#include "../Condvar/StdCondVar.hpp"
#endif

namespace Thread {

	template <class T, class U = AConsumer>
	class ThreadPool
	{
	public:
		explicit ThreadPool(unsigned int pNbThread);
		virtual ~ThreadPool();

	public:
		unsigned long pushInQueue(T *pElem);

	private:
		std::list<T*>   mQueue;
        ICondVar		*mCondQueue;
		std::vector<std::pair<U*, IThread *>> mThreads;
	};

}

#endif // THREADPOOL_HH
