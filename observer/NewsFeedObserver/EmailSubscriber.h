#ifndef EMAILSUBSCRIBER_H
#define EMAILSUBSCRIBER_H

#include "ISubscriber.h"
#include <string>
#include <list>

//forward declaration
class NewsPublisher;

class EmailSubscriber : public ISubscriber {
public:
	EmailSubscriber(const std::string& email);
	~EmailSubscriber();
	
	void addNewsPublisher(NewsPublisher*);
	void setEmailAddress(const std::string& addr);
	virtual void update(const NewsPublisher*) override;
protected:
	void sendEmail(const std::string& msg) const;
private:
	std::list<NewsPublisher*>	_publishers;
	std::string	_emailAddress;
};
#endif // !EMAILSUBSCRIBER_H
