#include "customer.h"

 QString &Customer::returnCustomerName()
 {
     return this->name;
 }

 QString &Customer::returnPassword()
 {
     return this->password;
 }

 void Customer::changeName(const QString mname)
 {
     name = mname;
 }

 int & Customer::returnProcess()
 {
     return this->process;

 }

