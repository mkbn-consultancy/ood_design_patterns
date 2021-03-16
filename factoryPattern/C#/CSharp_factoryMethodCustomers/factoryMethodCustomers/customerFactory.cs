using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace factoryMethodCustomers
{
    class customerFactory
    {
        public static customer GetCustomer(int i)
        {
            switch (i)
            {
                case 1:
                    goldCustomer goldCustomer = new goldCustomer();
                    goldCustomer.GoldOperation();
                    goldCustomer.AddPoints();
                    goldCustomer.AddDiscount();
                    return goldCustomer;
                case 2:
                    silverCustomer silverCustomer = new silverCustomer();
                    silverCustomer.SilverOperation();
                    silverCustomer.AddPoints();
                    silverCustomer.AddDiscount();
                    return silverCustomer;
                default: return null;
            }
        }
    }

}
