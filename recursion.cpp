#include <iostream>
#include <list>


int sum(std::list<int>&);
int count(std::list<int>& list);

int main() {
    // Write C++ code here
    std::list<int> mylist;
    mylist.push_back (10);
    mylist.push_back (2);
    mylist.push_back (300);
    std::cout << "count result : " << count(mylist) << std::endl;
    std::cout << "sum result : " << sum(mylist) << std::endl;
    return 0;
}

int sum(std::list<int>& list)
{
    if( list.size() == 0 )
    {
        return 0;
    }
    else
    {
        int front = list.front();
        list.pop_front();
        return front + sum(list);
    }
}

int count(std::list<int>& list)
{
    if(list.size() == 1)
    {
        return 1;
    }
    else
    {
        list.pop_front();
        return 1 + count(list);
    }
}
