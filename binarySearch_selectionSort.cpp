// Online C++ compiler to run C++ program online
#include <iostream>
#include <array>


template<std::size_t Size>
int binarySearch(const std::array<int,Size>&,  int);

template<std::size_t Size>
std::array<int,Size> selectionSort(const std::array<int,Size>&);

int main() {
    // Write C++ code here
    std::array<int,11> arr {{ 52,221,33,176,412,15,618,223,92,336,40 }};
    std::array<int,11> sorted = selectionSort(arr);
    for ( int elem : sorted )
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
    int position = binarySearch(sorted,223);
    std::cout << position << std::endl;
    return 0;
}

//binarySearch function takes a sorted array and an item.
//if the item is in the array, the function return its position.
template<std::size_t Size>
int binarySearch(const std::array<int,Size>& list, int item)
{
    int low = 0;
    int high = Size;
    while(low <= high)
    {
        int mid = (high + low) / 2;
        int guess = list[mid];
        if ( guess == item )
        {
            std::cout << "found the item. Index : ";
            return mid;
        }
        else if ( guess > item ) //too high
        {
            high = mid - 1;
        }
        else //too low
        {
            low = mid + 1;
        }
    }
    
    //Not Found
    return -1;
}

template<std::size_t Size>
int findSmallest(const std::array<int,Size>& arr, int startIndex)
{
    int smallest = arr[startIndex];
    int index = startIndex;
    for(int i = startIndex; i < Size; ++i)
    {
        if ( arr[i] < smallest )
        {
            smallest = arr[i];
            index = i;
        }
    }
    return index;
}

template<std::size_t Size>
std::array<int,Size> selectionSort(const std::array<int,Size>& Array)
{
    std::array<int,Size> ret = Array;
    for(int i = 0; i < Size; ++i)
    {
        int index = findSmallest(ret,i);
        std::swap(ret[i],ret[index]);
    }
    
    return ret;

}
