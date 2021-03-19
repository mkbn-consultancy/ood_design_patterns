/*
int numCustomers = 0;
int numOrders = 0;
int numItems = 0;

for(int i=0; i<customGrp.size(); i++){
    Customer* p = customGrp.getCustomer(i);
    ++numCustomers;
    for(int j=0; j<p->size(); ++j){
        Order* o = p...
        ++numOrders
        for(int k=0; k<o->size(); ++k){
            ++numItems;
        }
    }
}

class GeneralReport : public IVisior
{
public:
    virtual void accept(Item*){
        numItems++;
    }
private:
    int numCustomers = 0;
    int numOrders = 0;
    int numItems = 0;
}
*/