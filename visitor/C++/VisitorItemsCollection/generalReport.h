#include "ivisitor.h"
#include <tuple>

//forward declarations
class Customer;
class Order;
class Item;

class GeneralReportVisitor : public IVisitor
{
public:
    virtual void visit(Customer*) override;
    virtual void visit(Order*) override;
    virtual void visit(Item*) override;
   
    std::tuple<int,int,int> getResults() const;

private:
    int _numOfCustomers{0};
    int _numOfOrders{0};
    int _numOfItems{0};
};