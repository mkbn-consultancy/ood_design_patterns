#include "SMSSubscriber.h"
#include "NewsPublisher.h"

#include <iostream>

SMSSubscriber::SMSSubscriber(const std::string& phoneNum) {
	_phoneNumber = phoneNum;
}

SMSSubscriber::~SMSSubscriber() {
	for (auto pub : _publishers) {
		pub->detach(this);
	}
}

void SMSSubscriber::addNewsPublisher(NewsPublisher* pub) {
	_publishers.push_back(pub);
	pub->attach(this);
}

void SMSSubscriber::setPhoneNumber(const std::string& phoneNum) {
	//TODO: check that the phone number is valid
	_phoneNumber = phoneNum;
}
void SMSSubscriber::update(const NewsPublisher* pub) {
	sendSMS(pub->getLatestNews());
}

void SMSSubscriber::sendSMS(const std::string& msg) const {
	std::cout << "sending sms to number " << _phoneNumber << " with message: " << msg << std::endl;
}
