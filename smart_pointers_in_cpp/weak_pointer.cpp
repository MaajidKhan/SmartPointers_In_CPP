/*
weak_ptr

0. If we say unique_ptr is for unique ownership and shared_ptr is for shared ownership then
   weak_ptr is for non-ownership smart pointer.
1. It actually reference to an object which is managed by shared_ptr.

    This means to have a weak_ptr, there need to be an shared_ptr
2. A weak_ptr is created as a copy of shared_ptr.
3. We have to convert weak_ptr to shared_ptr in order to use the managed object.
4. It is used to remove cyclic dependency between shared_ptr.

*/

#include <iostream>
#include <memory>

int main() {
auto sharedPtr = std::make_shared<int>(100);
std::weak_ptr<int> weakPtr(sharedPtr); // weak_ptr can only be assigned to a shared_ptr
A weak_ptr is created as a copy of shared_ptr


std::cout << "weakPtr.use_count(): " << weakPtr.use_count() << std::endl; //weak_ptr can never increase the reference count.
std::cout << "sharedPtr.use_count(): " << sharedPtr.use_count() << std::endl;
std::cout << "weakPtr.expired(): " << weakPtr.expired() << std::endl; //Prints false(0), since weak_ptr is still active

if(std::shared_ptr<int> sharedPtr1 = weakPtr.lock()) { //Technically ur locking the first sharedPtr and assigning it to a new sharedPtr1
    // You will always have to initialize weakPtr to some sharedPtr1 to use it
    //If you don't initialize and the first actual shared_ptr goes off, then the new shared_ptr can't keep track of use_count().
    //There's a cyclic Dependency sp -> wp -> sp1

    std::cout << "*sharedPtr: " << *sharedPtr << std::endl; // We have to convert weak_ptr to shared_ptr in order to use the managed object.
    // If you see here we are dereferencing *sharedPtr to get the value rather than weakPtr

    std::cout << "sharedPtr1.use_count(): " << sharedPtr1.use_count() << std::endl; //prints count 2
}
else {
    std::cout << "Don't get the resource!" << std::endl;
}

weakPtr.reset(); // so this weakPtr is now not pointing towards the sharedPtr

if(std::shared_ptr<int> sharedPtr1 = weakPtr.lock()) { // Now that weakPtr is reset, sharedPtr1 won't be able to point to sharedPtr, because the
    //link b/w weakPtr and sharedPtr is already broken due to weakPtr.reset()
    std::cout << "*sharedPtr: " << *sharedPtr << std::endl;
    std::cout << "sharedPtr1.use_count(): " << sharedPtr1.use_count() << std::endl;
}
else {
    std::cout << "Don't get the resource!" << std::endl;
}



}
