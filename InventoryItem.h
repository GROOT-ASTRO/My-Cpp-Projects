// This class has overloaded constructors.
#ifndef INVENTORYITEM_H
#define INVENTORYITEM_H
#include <string>
#include <cstdlib>
using namespace std;

class InventoryItem
{
private:
   string description; 
   double cost;        
   int units;  

public:
   // Constructor 
   InventoryItem()
      { 
		description = "";
        cost = 0.0;
        units = 0; }
 
   InventoryItem(string desc, double c, int u)
      {
		description = desc;
        cost = c;
        units = u; }

   // Mutator functions
   void setDescription(string d) 
      { description = d; }

   void setCost(double c)
      { cost = c; }
      
   void setUnits(int u)
      { units = u; }

   // Accessor functions
   string getDescription() const
      { return description; }
         
   double getCost() const
      { return cost; }

   int getUnits() const
      { return units; }
};
#endif