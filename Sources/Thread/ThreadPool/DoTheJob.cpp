#include "DoTheJob.h"

template <typename T>
DoTheJob<T>::DoTheJob(Thread::ICondVar *cond_queue, std::list<T*> *queue) :
	AConsumer(cond_queue)
{
}

template <typename T>
DoTheJob<T>::~DoTheJob()
{
}

template <typename T>
void DoTheJob<T>::run()
{
	while (_run)
	{
		if (_queue->empty())
			_cond_queue->wait();
		else
		{
			T *job = _queue->front();
			_queue->pop_front();
			if (!_queue->empty())
				_cond_queue->signal();
		}
	}
}