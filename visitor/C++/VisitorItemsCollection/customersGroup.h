#include "ivisitable.h"
#include "customer.h"
#include <vector>

//forward declaration
class IVisitor;

class CustomersGroup : public IVisitable
{
public:
    virtual void accept(IVisitor*) override;
    void addCustomer(const Customer&);
private:
    std::vector<Customer> _customersInGroup;
};