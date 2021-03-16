using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace factoryMethodCustomers
{
    class Program
    {
        static void Main(string[] args)
        {
            customer c1 = customerFactory.GetCustomer(1);

            baseCustomerFactory c2 = new goldCustomerFactory();
            // Or new SilverCustomerFactory();
            customer objCust = c2.GetCustomer();

        }
    }
}
