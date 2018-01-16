#include "RThreadPool.h"

namespace Thread
{

	RThreadPool::RThreadPool()
	{
	}


	RThreadPool::~RThreadPool()
	{
		for (unsigned int i = 0; i < _threads.size(); i++)
			std::get<1>(_threads.at(i))->join();

		for (unsigned int i = 0; i < _threads.size(); i++) {
			std::get<1>(_threads.at(i))->kill();
			delete std::get<1>(_threads.at(i));
		}
		_threads.erase(_threads.begin(), _threads.end());
	}

	void	RThreadPool::addThread(unsigned int id, RType::GameInstance *game)
	{
		Thread::ICondVar	*var;
		/*#ifdef __linux__
		var = new UnixCondVar();
		IThread *thread = new UnixThread(&(RType::trampoline), game, var);
		_threads.push_back(std::make_tuple(id, thread, var, game));
		#else*/
		var = new StdCondVar();
		IThread *thread = new StdThread(&(RType::trampoline), game, var);
		_threads.push_back(std::make_tuple(id, thread, var, game));
		//#endif // __linux__
	}

	void	RThreadPool::removeThread(unsigned int i)
	{
		for (std::vector<std::tuple<unsigned int, IThread *, ICondVar *, RType::GameInstance *>>::iterator it = _threads.begin(); it != _threads.end(); ++it)
			if (std::get<0>(*it) == i)
			{
				_threads.erase(it);
				break;
			}
	}

	std::vector<std::tuple<unsigned int, IThread *, ICondVar *, RType::GameInstance *>>	RThreadPool::getThreads() const
	{
		return _threads;
	}

	std::tuple<unsigned int, IThread *, ICondVar *, RType::GameInstance *>				RThreadPool::getThreadById(unsigned int i)
	{
		for (std::vector<std::tuple<unsigned int, IThread *, ICondVar *, RType::GameInstance *>>::iterator it = _threads.begin(); it != _threads.end(); ++it)
			if (std::get<0>(*it) == i)
				return (*it);
	}
}
