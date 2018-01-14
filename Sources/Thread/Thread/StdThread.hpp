#ifndef Thread_StdThread_h
#define Thread_StdThread_h

#include <thread>
#include "IThread.h"

namespace Thread {

	class StdThread: public IThread
	{
	public:
		template <class T, class ...Args>
		explicit StdThread(T &&func, Args &&...params) :
			mThread(func, params...) {};

		virtual ~StdThread() {};

	public:
		void join() override;
		void kill() override;
		int getIdThread() const override;

	 private:
		std::thread mThread;
	};

} /* End of namespace Thread */

#endif // Thread_StdThread_h
