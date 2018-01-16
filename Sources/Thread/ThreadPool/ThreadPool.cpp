#include "ThreadPool.hh"

namespace Thread 
{

	template<class T, class U>
	ThreadPool<T, U>::ThreadPool(unsigned char nbThread)
	{
	  /*#ifdef __linux__
		_cond_queue = new UnixCondVar();
		#else*/
		_cond_queue = new StdCondVar();
		//#endif // __linux__

		for (unsigned char i = 0; i < nbThread; i++)
		{
			U *job = new U(_cond_queue, &_queue);

			/*#ifdef __linux__
			IThread *thread = new UnixThread(&DoTheJob::run, job, &_queue);
			#else*/
			IThread *thread = new StdThread(&DoTheJob::run, job, &_queue);
			//#endif // __linux__

			std::pair<job, IThread *> pair(job, thread);
			_threads.push_back(pair);
		}
	}

	template <class T, class U>
	ThreadPool<T, U>::~ThreadPool()
	{
		for (unsigned int i = 0; i < _threads.size(); i++)
		{
			_threads.at(i).first->stop();
			_threads.at(i).second->join();
		}
		for (unsigned int i = 0; i < _threads.size(); i++) {
			_threads.at(i).second->kill();
			delete _threads.at(i).first;
			delete _threads.at(i).second;
		}
		
		_threads.erase(_threads.begin(), _threads.end());

		delete _cond_queue;
	}

	template <class T, class U>
	bool ThreadPool<T, U>::pushInQueue(T *elem)
	{
		_queue.push_back(elem);
		_cond_queue->signal();
		return _queue.size();
	}

}
