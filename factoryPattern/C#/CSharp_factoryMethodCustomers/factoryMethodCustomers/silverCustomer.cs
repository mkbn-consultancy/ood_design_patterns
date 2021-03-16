using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace factoryMethodCustomers
{
    public class silverCustomer :customer
    {
        public void AddPoints()
        {
            Console.WriteLine("Silver Customer - Points Added");
        }

        public void AddDiscount()
        {
            Console.WriteLine("Silver Customer - Discount Added");
        }

        public void SilverOperation()
        {
            Console.WriteLine("Operation specific to Silver Customer");
        }
    }
}
