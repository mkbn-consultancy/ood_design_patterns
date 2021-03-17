#ifndef SUSSUBSCRIBER_H
#define SUSSUBSCRIBER_H

#include "ISubscriber.h"
#include <list>
#include <string>

//forward declaration
class NewsPublisher;

class SMSSubscriber : public ISubscriber {
public:
	SMSSubscriber(const std::string& phoneNum);
	~SMSSubscriber();

	void addNewsPublisher(NewsPublisher*);
	void setPhoneNumber(const std::string&);
	virtual void update(const NewsPublisher*) override;
protected:
	void sendSMS(const std::string&) const;

private:
	std::list<NewsPublisher*> _publishers;
	std::string		_phoneNumber;
};

#endif // !SUSSUBSCRIBER_H
