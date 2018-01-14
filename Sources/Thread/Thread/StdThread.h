#ifndef Thread_StdThread_h
#define Thread_StdThread_h

#include <thread>
#include "IThread.h"

namespace Thread {

	class StdThread: public IThread
	{
	public:
		template <class T, class ...Args>
		StdThread(T &&func, Args &&...params) :
			_thread(func, params...) {};

		~StdThread() {};

	public:
		void join() override
		{
			if (_thread.joinable())
				_thread.join();
		};

		void kill() override
		{
			_thread.detach();
		};

		int getIdThread() const override
		{
			return 0;
		};

	 private:
		std::thread _thread;
	};

} /* End of namespace Thread */

#endif // Thread_StdThread_h
