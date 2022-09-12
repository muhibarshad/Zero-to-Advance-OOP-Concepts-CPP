#include <iostream>

int main()
{
    std::string friendList[]{"Bilal", "Ahmad", "Ali", "Talha", "Hamza"};
    std::string name;
    std::cout << "Enter the your first name to find your are in my friend_list or not : \n";
    std::cin >> name;
    for (const auto &nameX : friendList)
    {
        nameX == name ? std::cout << "Yes you are in my friend list brother :\n" : std::cout << "No\n";
        if (nameX == name)
            break;
    }
}
/*For-each loops don’t only work with fixed arrays, they work with many kinds of list-like structures, such as vectors (e.g. std::vector), linked lists, trees, and maps. We haven’t covered any of these yet, so don’t worry if you don’t know what these are. Just remember that for each loops provide a flexible and generic way to iterate through more than just arrays.*/
// Also not work for the dynamic arrays

/*To get the index
    for (int i{ 0 };const auto &nameX : friendList)
    {
        nameX == name ? std::cout << "Yes you are in my friend list brother :\n" : std::cout << "No\n";
        if (nameX == name)
            break;
         ++i;

    }
*/
