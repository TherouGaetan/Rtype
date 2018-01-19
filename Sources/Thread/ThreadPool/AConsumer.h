#ifndef Thread_AConsumer_h_
#define Thread_AConsumer_h_

#include "../Condvar/ICondVar.h"

namespace Thread {

	class AConsumer {
	public:
		AConsumer();
		AConsumer(ICondVar *pCondvar);

	public:
		void			stop();
		virtual void	run() = 0;

	protected:
		bool		mRun;
		ICondVar	*mCondQueue;
	};

} /* End of namespace Thread */

#endif // !Thread_IConsumer_h_