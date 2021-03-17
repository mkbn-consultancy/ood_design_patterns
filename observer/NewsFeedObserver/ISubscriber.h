#ifndef ISUBSCRIBER_H
#define ISUBSCRIBER_H

//forward declaration
class NewsPublisher;

class ISubscriber {
public:
	virtual void update(const NewsPublisher*) = 0;
};

#endif // !ISUBSCRIBER_H
