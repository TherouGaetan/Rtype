#include "AConsumer.h"

namespace Thread {
	
	AConsumer::AConsumer(ICondVar * cond_queue)
	{
		_run = true;
		_cond_queue = cond_queue;
	}

	void AConsumer::stop()
	{
		_run = false;
	}

}