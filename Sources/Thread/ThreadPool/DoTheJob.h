#ifndef Thread_DoTheJob_h_
#define Thread_DoTheJob_h_

#include <list>
#include "../Condvar/ICondVar.h"
#include "AConsumer.h"

namespace Thread {

	template<class T>
	class DoTheJob : public AConsumer {
	public:
		DoTheJob(Thread::ICondVar *pCondQueue, std::list<T *> *pQueue);

		~DoTheJob();

	public:
		void run() override;

	public:
		std::list<T *> *mQueue;
	};

}

#endif // !Thread_DoTheJob_h_