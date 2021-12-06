#include "EconomyNewsPublisher.h"
#include "PoliticsNewsPublisher.h"
#include "SMSSubscriber.h"
#include "EmailSubscriber.h"

#include <iostream>

int main() 
{
	//two news-producers
	EconomyNewsPublihser economyNP;
	PoliticsNewsPublisher politicsNP;

	//two news-consumers
	EmailSubscriber emailSub("miri@mkbn.co.il");
	emailSub.addNewsPublisher(&economyNP);

	SMSSubscriber smsSub("05064976003");
	smsSub.addNewsPublisher(&economyNP);
	smsSub.addNewsPublisher(&politicsNP);

	//produce new data
	std::cout<<"\n----breaking news: No fees from today!\n";
	economyNP.addNews("No fees from today!");
	std::cout<<"\n----breaking news: Elections are coming!\n";
	politicsNP.addNews("Elections are coming!");
	std::cout<<std::endl;
}