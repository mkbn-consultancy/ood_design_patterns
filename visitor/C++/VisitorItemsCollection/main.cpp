#include "customersGroup.h"
#include "customer.h"
#include "item.h"
#include "order.h"
#include "generalReport.h"

#include <iostream>

int main()
{
    Customer c1("Customer1");
    Order o1("order1");
    o1.addItem("item1");
    o1.addItem("item2");
    Order o2("order2");
    o2.addItem("item1");
    Order o3("order3");
    o3.addItem("item2");
    o3.addItem("item3");

    c1.addOrder(o1);
    c1.addOrder(o2);
    c1.addOrder(o3);

    //..................

    Customer c2("Customer2");
    Order o4("order_a");
    o4.addItem("item1");
    o4.addItem("item5");
    Order o5("order_b");
    o5.addItem("item2");
    c2.addOrder(o4);
    c2.addOrder(o5);

    //..................

    CustomersGroup custGrp;
    custGrp.addCustomer(c1);
    custGrp.addCustomer(c2);

    //..................

    GeneralReportVisitor report1;
    custGrp.accept(&report1);

    //..................

    auto[numItems,numOrders,numCust] = report1.getResults();
    std::cout<<"General Report Result:\n";
    std::cout<<"num of items: "<<numItems<<std::endl;
    std::cout<<"num of orders: "<<numOrders<<std::endl;
    std::cout<<"num of customers: "<<numCust<<std::endl;
}