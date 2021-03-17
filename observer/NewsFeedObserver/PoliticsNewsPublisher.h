#ifndef POLITICSNEWS_H
#define POLITICSNEWS_H

#include "NewsPublisher.h"

class PoliticsNewsPublisher : public NewsPublisher {
public:
	PoliticsNewsPublisher() {
		//connect to a server to get information, etc'.
	}
	~PoliticsNewsPublisher() {
		//clear data
	}
	//extra methods
	//...

};
#endif // !POLITICSNEWS_H
