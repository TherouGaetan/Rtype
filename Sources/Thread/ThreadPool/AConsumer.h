#ifndef Thread_AConsumer_h_
#define Thread_AConsumer_h_

#include "../Condvar/ICondVar.h"

namespace Thread {

	class AConsumer {
	public:
		AConsumer(ICondVar *cond_queue);

	public:
		void			stop();
		virtual void	run() = 0;

	protected:
		bool		_run;
		ICondVar	*_cond_queue;
	};

} /* End of namespace Thread */

#endif // !Thread_IConsumer_h_