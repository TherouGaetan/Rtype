#ifndef THREADPOOL_HH
#define THREADPOOL_HH

#include <list>
#include <vector>
#include <utility>

#include "DoTheJob.h"
#include "../Thread/IThread.h"
/*#ifdef __linux__
#include "UnixThread.h"
#include "UnixCondVar.h"
#else*/
#include "../Thread/StdThread.h"
#include "../Condvar/StdCondVar.h"
//#endif // !__linux__


namespace Thread {

	template <class T, class U = AConsumer>
	class ThreadPool
	{
	public:
		ThreadPool(unsigned char nbThread);
		~ThreadPool();

	public:
		bool pushInQueue(T *elem);

	private:
		std::list<T*>   _queue;
		std::vector<std::pair<DoTheJob<T>*, IThread *>> _threads;
		ICondVar		*_cond_queue;
	};

}

#endif // THREADPOOL_HH
