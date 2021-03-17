#ifndef ECONOMYNEWS_H
#define ECONOMYNEWS_H

#include "NewsPublisher.h"

class EconomyNewsPublihser : public NewsPublisher{
public:
	EconomyNewsPublihser() {
		//connect to a server to get information, etc'.
	}
	~EconomyNewsPublihser() {
		//clear data
	}
	//extra methods
	//...
};

#endif //ECONOMYNEWS_H