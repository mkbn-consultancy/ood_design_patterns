#ifndef NEWSPUBLISHER_H
#define NEWSPUBLISHER_H

#include <string>
#include <list>

//forward declaration
class ISubscriber;

class NewsPublisher {
public:
	void attach(ISubscriber*);
	void detach(ISubscriber*);

	void addNews(const std::string&);
	std::string getLatestNews() const;
protected:
	void notifySubscribers() const;

private:
	std::list<ISubscriber*>	_subscribers;
	std::string _strLatestNews;
};

#endif // !NEWSPUBLISHER_H

