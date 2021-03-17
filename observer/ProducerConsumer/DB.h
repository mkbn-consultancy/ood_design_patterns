#pragma once

#include <string>
#include <list>
#include "observer.h"

class DB
{
public:
	static DB* instance() {
		//not thread safe!
		if (!_theInstance) {
			_theInstance = new DB;
		}
		return _theInstance;
	}

	//write new data to DB and update all observers
	void putData(const std::string& data) {
		_data = data;
		for (auto itr : _observers) {	//notify all observers
			(itr)->update();
		}
	}
	const std::string& getData() const {
		return _data;
	}

	//methods for observers:
	void subscribe(IObserver* p) {
		_observers.push_back(p);
	}
	void unsbscribe(IObserver* p) {
		_observers.remove(p);
	}

protected:
	DB() {}

private:
	std::string _data;
	static DB* _theInstance;
	std::list<IObserver*> _observers;
};

DB* DB::_theInstance = nullptr;