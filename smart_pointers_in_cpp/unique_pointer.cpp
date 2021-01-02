/*
unique pointer in c++

// NOTES:
0. unique_ptr is a class template.
1. unique_ptr is one of the smart pointer provided by
c++11 to prevent memory leaks.
2. unique_ptr wraps a raw pointer in it, and de-allocates the
raw pointer, when unique_ptr object goes out of scope.
3.similar to actual pointers we can use -> and * on the object of
unique_ptr, because it is overloaded in unique_ptr class
4. when exception comes then also it will de-allocate the memory
hence no memory leak.
5. Not only object we can create array of objects of unique_ptr.

Operations:
release, reset, swap, get, get_deleter
*/

#include<iostream>
#include<memory>
using namespace std;

class Foo {
private:
    int x;
public:
    explicit Foo(int x): x{x} {}
    int getX() { return x; }
    ~Foo()
    {
        cout << "Destructor() being called" << endl;
        cout << "Foo Dest" << endl;
    }
};

int main() {
    /* Manual Method
    Foo *f = new Foo(10);
    cout << f->getX() << endl;
    delete f; // we need to manually delete this memory pointer to avoid memory leaks
    */
    cout << endl; cout << endl;
    // Using unique_ptr
    std::unique_ptr<Foo> p(new Foo(10)); // No need to delete this pointer, it is now automatically taken care of
    /*
    This object p is created on stack rather than heap and This destructor ~Foo()
    will call delete for this pointer p when this goes out of scope.

    -> Very Light weight, only 1 ownership
    */
    cout << p->getX() << endl;




    cout << endl; cout << endl;
    //Different ways of declaring a unique_ptr
    cout << "Different ways of declaring a unique_ptr: " << endl;
    //Method 1
    unique_ptr<Foo> p1(new Foo(101)); // This is Not Exception safe  (Method 1)

    //Method 2
    unique_ptr<Foo> p2 = make_unique<Foo>(20); // This is exception safe and is the preferred way of declaring an unique_ptr  (Method 2)

    //Method 3
    Foo *f1 = new Foo(10);
    unique_ptr<Foo> p3(f1);




    cout << endl; cout << endl;
    //calling the class methods using unique_ptr
    cout << "Different ways of calling the class methods using unique_ptr" << endl;
    cout << " p1->getX() : " << p1->getX() << " and  (*p1).getX() : " << (*p1).getX() << endl;
    cout << " p2->getX() : " << p2->getX() << "and   (*p2).getX() : " << (*p2).getX() << endl;

    cout << endl; cout << endl;
    //copying unique_ptr
    cout << "copying unique_ptr" << endl;
    // p1 = p2; //This will fail because you cannot copy ownership when using unique_ptr

    //But if you want to move
    unique_ptr<Foo> p4 = std::move(p1); // PASS: Moving ownership is allowed, Only copying is not allowed.
    //Now p1 ownership is transferred to p4, now p1 is a null ptr.




    cout << endl; cout << endl;
    cout << "Operations of a unique_ptr:" << endl;
    //Operations of a unique_ptr

    //get operation
    Foo *pg = p4.get(); // you just get a pointer of p4 object
    cout << "p->getX() : " << pg->getX() << endl; //Prints 101

    //Release Operation
    Foo *p5 = p4.release(); //p5 gets the managed object new Foo(101) from p1
    cout << "p5->getX() : " << p5->getX() << endl; // prints 101
    //cout << "p4->getX() : " << p4->getX() << endl; // p4 prints nothing as it just turned null_ptr as it got released




    cout << endl; cout << endl;
    cout << "Reset Operation" << endl;
    //Reset Operation
    //Before Reset
    cout << "[Before Reset] p2->getX() : " << p2->getX() << endl; // prints 20

    //After Reset
    p2.reset(p5); // p2 will now point to p5 object. Just p2's managed object got changed to p5
    cout << "[After Reset] p2->getX() : " << p2->getX() << endl; // prints 101
    cout << endl; cout << endl;


    cout << "swap operation" << endl;
    unique_ptr<Foo> swap1 = make_unique<Foo>(999);
    unique_ptr<Foo> swap2 = make_unique<Foo>(777);

    cout << "swap1->getX(): " << swap1->getX() << endl;
    cout << "swap2->getX(): " << swap2->getX() << endl;

    swap1.swap(swap2);
    cout << "After swapping is done" << endl;
    cout << "swap1->getX(): " << swap1->getX() << endl;
    cout << "swap2->getX(): " << swap2->getX() << endl;


    return 0;
}


