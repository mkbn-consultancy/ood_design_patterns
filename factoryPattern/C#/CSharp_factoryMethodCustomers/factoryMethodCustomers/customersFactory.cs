using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace factoryMethodCustomers
{
    public class goldCustomerFactory : baseCustomerFactory
    {
        public override customer CreateCustomer()
        {
            goldCustomer objCust = new goldCustomer();
            objCust.GoldOperation();
            return objCust;
        }
    }
    public class silverCustomerFactory : baseCustomerFactory
    {
        public override customer CreateCustomer()
        {
            silverCustomer objCust = new silverCustomer();
            objCust.SilverOperation();
            return objCust;
        }
    }
}
