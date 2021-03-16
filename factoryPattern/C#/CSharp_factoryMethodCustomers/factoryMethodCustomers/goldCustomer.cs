using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace factoryMethodCustomers
{
    public class goldCustomer :customer
    {
        public void AddPoints()
        {
            Console.WriteLine("Gold Customer - Points Added");
        }

        public void AddDiscount()
        {
            Console.WriteLine("Gold Customer - Discount Added");
        }

        public void GoldOperation()
        {
            Console.WriteLine("Operation specific to Gold Customer");
        }
    }
}
