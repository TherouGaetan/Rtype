#pragma once

#include <vector>
#include <tuple>

#include "../Thread/IThread.h"
#include "../Condvar/ICondVar.h"
/*#ifdef __linux__
#include "../Thread/UnixThread.h"
#include "../Condvar/UnixCondVar.h"
#else*/
#include "../Condvar/StdCondVar.h"
#include "../Thread/StdThread.h"
//#endif
#include "../../UDP/GameInstance.h"

namespace Thread
{
	class RThreadPool
	{
	public:
		RThreadPool();
		~RThreadPool();

		void																				addThread(unsigned int id, RType::GameInstance *);
		void																				removeThread(unsigned int);
		std::vector<std::tuple<unsigned int, IThread *, ICondVar *, RType::GameInstance *>>	getThreads() const;
		std::tuple<unsigned int, IThread *, ICondVar *, RType::GameInstance *>				getThreadById(unsigned int);

	private:

		std::vector<std::tuple<unsigned int, IThread *, ICondVar *, RType::GameInstance *>>	_threads;
	};

}
