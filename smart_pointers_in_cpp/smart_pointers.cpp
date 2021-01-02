/*

NOTES:
1. smart pointer is a class which wraps a raw pointer , to manage the lifetime of the pointer

In this video we will learn what is the actual use of smart pointers in c++.
It is basically a wrapper which wraps raw pointer and handles the life time of the object for you,
means if there is no reference to the pointer it will delete it otherwise it will hold.

2. It will make sure that the object is deleted if it is not referenced any more.

Trivia:
auto_ptr is deprecated in c++11, it's not there in c++ 17

There are basically three types of smart pointers.
TYPES:
1. unique_ptr
2. shared_ptr
3. weak_ptr
And the basic job of smart pointer is, it actually makes sure that we don't have memory leaks.

*/

/* unique_ptr:
-> Allows only one owner of the underlying pointer
-> you cannot copy the object of the unique_ptr
-> you can move it and take the reference/pointer of it
-> your pointer will be single all the time
*/

/* shared_ptr:
-> Allows multiple owners of the same pointer (Reference count is maintained)
*/

/* weak_ptr:
-> It is a special type of a shared_ptr which doesn't count the reference
-> when you have two shared pointers and both have cyclic dependency, one can be made weak_ptr
*/


// This a just a demo of how smart pointers works

#include <iostream>
using namespace std;

class MyInt
{
public:
    explicit MyInt(int *p=nullptr)
    {
        data = p;
    }
    ~MyInt()
    {
        delete data;
    }
    int& operator * () { return *data; }
private:
    int *data;
};

int main()
{
    int *p = new int(10); // Here p will point to the address where value 10 is stored, say 1000 is the address
    MyInt myint = MyInt(p);
    cout << *myint << endl; // This will print the value as 10, since we are dereferencing the pointer using operator * ()
    return 0;
}
// when the main() function gets over, all the variables loose their scope and the destructor gets called.
/*
~MyInt()
    {
        delete data;
    }
// This deleted the pointer and clears the memory.
*/
