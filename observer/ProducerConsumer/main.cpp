#include "DB.h"
#include "Consumer.h"
#include "producer.h"
#include <vector>

class ThirdParty {
public:
	void readData() const {}
};

class ThirdPartyAdapter : private ThirdParty, public Consumer{
public:
	ThirdPartyAdapter(int id) : Consumer(id){
		DB::instance()->subscribe(this);
	}
	virtual void update() override {
		readData();
	}
	void getDataFronDB() const {
		readData();
	}
};

int main() {
	
	Producer p;

	Consumer c1(1);
	Consumer c2(2);
	Consumer c3(3);
	ThirdPartyAdapter a(4);

	p.putDataOnDB("hello");

	return 0;
}