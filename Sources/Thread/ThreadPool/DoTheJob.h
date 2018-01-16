#ifndef Thread_DoTheJob_h_
#define Thread_DoTheJob_h_

#include <list>
#include "../Condvar/ICondVar.h"
#include "AConsumer.h"

template <class T>
class DoTheJob : public Thread::AConsumer
{
public:
	DoTheJob(Thread::ICondVar *cond_queue, std::list<T*> *queue);
	~DoTheJob();

public:
	void	run() override;

public:
	std::list<T*>	*_queue;
};

#endif // !Thread_DoTheJob_h_