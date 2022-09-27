#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Item
{
private:
    int id;
    string name;
    int quantity;
    float cost;

public:
    // MUTATORS
    void setID(int);
    void setName(string);
    void setQuantity(int);
    void setCost(float);

    // ACCESSORS
    int getID() const;
    string getName() const;
    int getQuantity() const;
    float getCost() const;

    // CONSTRUCTORS
    Item();
    Item(int, string, float);
    Item(int, string, int);
    Item(int, string, int, float);
    Item(const Item &);

    // SET_ITEM_GET_ITEM_PUT_ITEM
    void getItem();
    void putItem() const;
    void setItem(int, string, int, float);

    float getTotalCost() const;
    bool isEqual(const Item &) const;
    void updateName(Item[], const int &) const;
    void getAveragePrice(const Item[], const int &);
   static float getMinimumCostItem(const Item[], const int &);

    // DESTRUCTOR
    ~Item();
};

// MUTATORS
void Item::setID(int id)
{
    this->id = id > 0 ? id : 0;
}
void Item::setName(string name)
{
    this->name = name;
}
void Item::setQuantity(int quantity)
{
    this->quantity = quantity > 0 ? quantity : 0;
}
void Item::setCost(float cost)
{
    this->cost = cost > 0 ? cost : 0;
}

// ACCESSORS
int Item::getID() const { return this->id; }
string Item::getName() const { return this->name; }
int Item::getQuantity() const { return this->quantity; }
float Item::getCost() const { return this->cost; }

// CONSTRUCTORS
Item::Item()
{
    this->id = 0;
    this->name = "";
    this->quantity = 0;
    this->cost = 0;
}
Item::Item(int id, string name, float cost)
{
    setID(id);
    setName(name);
    setCost(cost);
    setQuantity(0);
}
Item::Item(int id, string name, int quantity)
{
    setID(id);
    setName(name);
    setQuantity(quantity);
    setCost(0);
}
Item::Item(int id, string name, int quantity, float cost)
{
    setID(id);
    setName(name);
    setQuantity(quantity);
    setCost(cost);
}
Item::Item(const Item &obj)
{
    this->id = obj.id;
    this->name = obj.name;
    this->quantity = obj.quantity;
    this->cost = obj.cost;
}

// SET_ITEM_GET_ITEM_PUT_ITEM
void Item::setItem(int id, string name, int quantity, float cost)
{
    setID(id);
    setName(name);
    setQuantity(quantity);
    setCost(cost);
}
void Item::getItem()
{
    cout << "Enter the item\'s item number : ";
    cin >> id;
    setID(id);
    cin.ignore();
    cout << "Enter the name of item : ";
    getline(cin, name);
    setName(name);
    cout << "Enter the quantity of item : ";
    cin >> quantity;
    setQuantity(quantity);
    cout << "Enter the cost of the item : ";
    cin >> cost;
    setCost(cost);
}
void Item::putItem() const
{
    cout << "The item\'s item number : " << id << "\n";
    cout << "The name of item : " << name << "\n";
    cout << "The quantity of item : " << quantity << "\n";
    cout << "The cost of the item : " << cost << "\n";
}

// ARITHEMATIC_MEMBER_FUNCTIONS
float Item::getTotalCost() const
{
    return quantity >= 1 ? quantity * cost : 0;
}
bool Item::isEqual(const Item &obj) const
{
    return ((id == obj.id) && (name == obj.name) && (quantity == obj.quantity) && (cost == obj.cost));
}

void Item::updateName(Item arr[], const int &size) const
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i].id == id)
            arr[i].name = name;
    }
}
float Item::getMinimumCostItem(const Item arr[], const int &size) 
{
    int min_cost = arr[0].cost;
    for (int i = 0; i < size; i++)
    {
        if (arr[i].cost < min_cost)
        {
            min_cost = arr[i].cost;
        }
    }
    return min_cost;
}
void Item::getAveragePrice(const Item arr[], const int &size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i].cost;
    }
    this->cost = sum / size;
}

// DESTRUCTOR
Item::~Item()
{
    cout << "DESTRUCTOR EXECUTED"
         << "\n";
}

int main()
{
    // INITLIZING_STUDENT(_Testing_Constructors)
    const int size=4;
    Item item[size] = {Item(), Item(2, "Paint", 6), Item(3, "shirt", 700), Item(2, "Belt", 10, 200)};

    // DECLARING_STUDENT
    item[0].setItem(7, "PI_Cap", 100, 200);
    item[1].setItem(8, "Scocks", 20, 20);
    item[2] = item[0]; // calling_Copy_Constructor
    item[3].setItem(8, "Shoes", 10, 1500);

    // FORMATTING_DATA
    cout << left;
    cout << setw(15) << "ITEM_NO" << setw(20) << "ITEM_NAME" << setw(20) << "ITEM_QUANTITY" << setw(27) << "ITEM_PER_UNIT_PRICE" << setw(25) << "TOTAL_COST" << "\n";

    // DISPLAYING_STUDENT(_Testing_Member_Functions)
    for (const auto &item : item)
    {
        cout << setw(15) << item.getID() << setw(20) << item.getName() << setw(20) << item.getQuantity() << setw(27) << item.getCost()<< setw(25) << item.getTotalCost() << "\n";
    }
    cout<<"-------------------------------------------------------------------------"<<"\n";

    //ISEQUAL_UPDATION_MINIMUM_AVERAGE
    cout<<item[0].isEqual(item[2])<<"\n";
    item[1].updateName(item,size);
    cout<<"The minimum cost of item in the array = "<<Item::getMinimumCostItem(item,size)<<"\n";
    item[0].getAveragePrice(item,size);
    cout<<"The average cost of all the items in the array = "<<item[0].getCost()<<"\n";


    return 0;
}