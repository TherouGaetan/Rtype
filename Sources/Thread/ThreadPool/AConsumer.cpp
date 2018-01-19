#include "AConsumer.h"
#include "../ThreadFactory.hpp"

namespace Thread {
	
	AConsumer::AConsumer()
            : mRun(true)
	{
		mCondQueue = ThreadFactory::getInstance().makeCondVar();
	}

    AConsumer::AConsumer(ICondVar *pCondvar)
            : mRun(true), mCondQueue(pCondvar)
    {

    }

	void AConsumer::stop()
	{
		mRun = false;
	}

}