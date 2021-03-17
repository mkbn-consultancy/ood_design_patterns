#include "EmailSubscriber.h"
#include "NewsPublisher.h"
#include <iostream>

EmailSubscriber::EmailSubscriber(const std::string& email) {
	_emailAddress = email;
}

EmailSubscriber::~EmailSubscriber() {
	NewsPublisher* pub;
	for (auto pub : _publishers){
		pub->detach(this);
	}
}

void EmailSubscriber::addNewsPublisher(NewsPublisher* pub) {
	pub->attach(this);
	_publishers.push_back(pub);
}

void EmailSubscriber::setEmailAddress(const std::string& email) {
	_emailAddress = email;
}

void EmailSubscriber::update(const NewsPublisher* pub) {
	sendEmail(pub->getLatestNews());
}

void EmailSubscriber::sendEmail(const std::string& msg) const {
	std::cout << "sending email to address " << _emailAddress << " with message: " << msg << std::endl;
}