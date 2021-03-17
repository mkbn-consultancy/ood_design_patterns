#include "NewsPublisher.h"
#include "ISubscriber.h"

void NewsPublisher::attach(ISubscriber* sub) {
	_subscribers.push_back(sub);
}

void NewsPublisher::detach(ISubscriber* sub) {
	_subscribers.remove(sub);
}

void NewsPublisher::notifySubscribers() const {
	for (auto sub : _subscribers){
		sub->update(this);
	}
}

void NewsPublisher::addNews(const std::string& news) {
	_strLatestNews = news;
	notifySubscribers();
}

std::string NewsPublisher::getLatestNews() const {
	return _strLatestNews;
}
