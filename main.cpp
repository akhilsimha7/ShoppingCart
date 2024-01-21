#include <iostream>
#include <iomanip>
using namespace std;

class Item
{
public:
    string product;
    int serialNumber;
    int price;
    Item *next;
};

void addProduct(string name, int serialNumber, int price, Item **n)
{
    Item *newItem = new Item();
    newItem->product = name;
    newItem->serialNumber = serialNumber;
    newItem->price = price;
    newItem->next = *n;
    *n = newItem;
}

void removeProduct(string itemName, Item **m)
{
    Item *removal = *m;
    while (removal != NULL)
    {
        if (removal->product == itemName)
        {
        }
        else
            removal = removal->next;
    }
}
int getTotal(Item *n)
{
    int total = 0;
    while (n != NULL)
    {
        total += n->price;
        n = n->next;
    }
    return total;
}

void printList(Item *n)
{
    cout << left << setw(15) << "Product" << setw(20) << "Serial Number"
         << "Price(Euros)"
         << "\n";
    cout << "----------------------------------------------\n";

    while (n != NULL)
    {
        cout << setw(15) << n->product << setw(20) << n->serialNumber << n->price << "\n";

        n = n->next;
    }
}

int main()
{
    Item *head = nullptr;
    addProduct("Milk", 1122, 12, &head);
    addProduct("Bread", 1122, 12, &head);
    printList(head);
    int total = getTotal(head);
    cout << "Your Total Cost is: " << total << " Euros" << endl;
    //removeProduct("Bread", &head);
    //printList(head);
    return 0;
}