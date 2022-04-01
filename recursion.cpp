#include <iostream>
#include <list>
#include <string>

int sum(const std::list<int>&);
int count(const std::list<int>& list);
std::string binarySearch(const std::list<int>& list, int item);

int main() {
    // Write C++ code here
    std::list<int> mylist;
    mylist.push_back(2);
    mylist.push_back(3);
    mylist.push_back(7);
    mylist.push_back(17);
    mylist.push_back(21);
    mylist.push_back(33);
    mylist.push_back(67);
    mylist.push_back(70);
    mylist.push_back(99);
    std::cout << "list size :" << mylist.size() << std::endl;
    std::cout << "binary search result : "  << binarySearch(mylist , 21) << std::endl;
    
    std::cout << "count result : " << count(mylist) << std::endl;
    std::cout << "sum result : " << sum(mylist) << std::endl;
    return 0;
}

int sum(const std::list<int>& list)
{
    if( list.size() == 0 )
    {
        return 0;
    }
    else
    {
        int front = list.front();
        std::list<int> newList(++list.begin(),list.end());
        return front + sum(newList);
    }
}

int count(const std::list<int>& list)
{
    if(list.size() == 1)
    {
        return 1;
    }
    else
    {
        std::list<int> newList(++list.begin(),list.end());
        return 1 + count(newList);
    }
}

std::string binarySearch(const std::list<int>& list, int item)
{
    int high = list.size() - 1;
    int middle = high / 2;
    if( list.size() == 0)
    {
        return "Not Found";
    }
    else
    {
        if(*std::next(list.begin(), middle) == item)
        {
             return "Found";
        }
        else if (*std::next(list.begin(), middle) > item )
        {
            std::list<int> newList;
            newList.assign(list.begin(),std::next(list.begin(),middle));
            return binarySearch(newList,item);
        }
        else
        {
            std::list<int> newList;
            newList.assign(std::next(list.begin(),middle + 1),list.end());
            return binarySearch(newList,item);
        }
    }
    
     return "Not Found";
}
