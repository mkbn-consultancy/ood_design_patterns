#pragma once

#include "DB.h"
#include "observer.h"
#include <iostream>

//consumes data from DB when there is a new data
class Consumer : public IObserver
{
public:
	Consumer(int id) : _id(id) {
		DB::instance()->subscribe(this);
	}
	~Consumer() {
		DB::instance()->unsbscribe(this);
	}
	//callback method
	virtual void getDataFronDB() const {
		std::cout<<_id<<":"<<DB::instance()->getData()<<std::endl;
	}
	virtual void update() override {
		getDataFronDB();
	}

private:
	int _id;
}; 