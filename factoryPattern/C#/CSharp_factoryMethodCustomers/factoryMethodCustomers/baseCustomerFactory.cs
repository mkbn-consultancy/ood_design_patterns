using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace factoryMethodCustomers
{
    public abstract class baseCustomerFactory
    {
        public customer GetCustomer()
        {
            customer myCust = this.CreateCustomer();
            myCust.AddPoints();
            myCust.AddDiscount();
            return myCust;
        }
        public abstract customer CreateCustomer();
    }

}
