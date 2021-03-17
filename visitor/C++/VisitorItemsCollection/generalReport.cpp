#include "generalReport.h"
 
void GeneralReportVisitor::visit(Customer* c){
    _numOfCustomers++;
 }

 void GeneralReportVisitor::visit(Order* o){
     _numOfOrders++;
 }

 void GeneralReportVisitor::visit(Item* i){
     _numOfItems++;
 }

 std::tuple<int,int,int> GeneralReportVisitor::getResults() const{
     return std::make_tuple(_numOfItems,_numOfOrders,_numOfCustomers);
 }