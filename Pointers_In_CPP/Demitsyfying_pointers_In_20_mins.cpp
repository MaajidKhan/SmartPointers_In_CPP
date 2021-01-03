// Mastering c++ pointers with Rachit

#include <iostream>
using namespace std;

int main() {
printf("Mastering c++ pointers from scratch!");

int x = 1; // x is an integer and it goes into stack section of the memory
//Here the x can be anything (int, char, float, string, object of a class)
cout << "Value of x is: " << x << endl;

cout << "Address of x when x=1 is: " << &x << endl;

x = 100;
cout << "Address of x when x =100 is: " << &x << endl; //The address doesn't change because the memory for an element x has already been allocated

//what is a pointer. They point to object (int, char, float, string, object of a class) .
// It essentially only containing a address of something (object) to which it is pointing to..


//pointers can be declared as int* ptr (or) int *ptr
int *ptr = (int*)0x61ff04; //pointing to x, retrieve values using * pointer
// retrieve the address of a variable ==> &x

printf("My first pointer ptr = %p\n", ptr); // ptr will be pointing to the address as per it's property. prints 0x61ff04
printf("Value pointed to my pointer ptr = %d\n", *ptr); // *ptr will obviously will print the value stored by ptr. prints 100


cout<<endl;
*ptr = -100; //Assigning the value of the ptr to -100
printf("The Address of ptr = %p\n", ptr); // ptr will be pointing to the same address as before. prints 0x61ff04
printf("Value pointed to my pointer ptr = %d\n", *ptr); // *ptr will now print the value stored by ptr. prints -100
printf("Value of x is: %d ", x); // x = -100

cout<<endl;
//How to make a new pointer to point to the address of x
int *ptr2 = &x; // Essentially now ptr2 == ptr as ptr2 will start pointing to x
printf("The Address of ptr2 = %p\n", ptr2);
printf("Value pointed to my pointer ptr2 = %d\n", *ptr2);

char *name = "maajid"; //name becomes a pointer
printf("The size of pointer to an integer %lu\n", sizeof(ptr2)); // lu is unsigned long literal
printf("The size of pointer to character array %lu\n", sizeof(name));
//The size of both int(4 byte) and char(1 byte) is 4 bytes, since the pointer stores a hexa decimal address and we have a 32 bit machine.
// so 32 bits / 8 = 4 bytes
cout << endl;

//why do pointers have need a type - int*, char*, myclass*. Can't they be declared to anytype cause it's anyway pointing to the address only.
//Here is the answer why the data type of the pointer is important

//If your pointer is holding a int value, each address will be incremented by 4, because each element requires 4 bytes
printf("Content of ptr %p\n", ptr);
printf("Content of ptr+1 %p\n", ptr+1);
printf("Content of ptr+2 %p\n", ptr+2);

//If your pointer is holding a char value, each address will be incremented by 1, because each element in char requires just 1 byte
printf("Content of name %p\n", name);
printf("Content of name+1 %p\n", name+1);
printf("Content of name+2 %p\n", name+2);

cout<<endl;


//By default array is an pointer pointing to some object and storing the memory address
//By default the pointer will pointing to first indexed element of the array
int arr[3] = {10, 31, 999}; // arr actually becomes a pointer to the first element of array
printf("Content of arr %p, val = %d\n", arr, *arr);
printf("Content of arr+1 %p, val = %d\n", arr+1, *(arr+1)); // *(arr+1) ==> arr[1]
printf("Content of arr+2 %p, val = %d\n", arr+2, *(arr+2));
//Each indexed element will vary by 4 bytes
cout<<endl;


int *other = arr; // Equality operation
//we are not copyying the full arr, we are just copying the pointer
//It will point to same address and values as above(arr)
printf("Content of other %p, val = %d\n", other, *other);
printf("Content of other+1 %p, val = %d\n", other+1, *(other+1)); // *(arr+1) ==> arr[1]
printf("Content of other+2 %p, val = %d\n", other+2, *(other+2));
cout<<endl;


struct Real {
    int real, imag;
    void out() { printf("(%d + %di)\n", real, imag); }
};

/*
Real num;
num.real = 25;
num.imag = 77;
num.out();
*/
Real num = {1, 1}; //You can Initalize data variables of a struct this way also as they are public by default
num.out(); //Prints (1 + 1i)

Real* p = &num; //creating a pointer for the struct Real an making it point to address of num using &num
// p starts pointing to our num variable, object of our struct
p->out(); // -> arrow operator
//with pointer you can use only an arrow operator

cout <<"Printing using Dereferenced actual Real Object" << endl;
(*p).out(); //Dereferencing operator to get the actual real object so that now you can use . operator like usual .out()

printf("Real = %d\n", p->real); // arrow operators
printf("Imag = %d\n", p->imag);

printf("Real = %d\n", (*p).real); // Dereferencing
printf("Imag = %d\n", (*p).imag);
cout << endl;

//You should be careful while working with Dereferenced objects
Real num2 = *p; // num2 will be equal to the value p holds
num2.real = 13;
num2.out();    // This will print 13 for the real part  (13 +1i)
p->out();   // This will print the actual value 1 itself for the real part and the above change has not been reflected in the dereferenced object (1+ 1i)


//Solution: Always use the arrow operator to change the value
p->real =13; // p is pointing to some object / real number
p->out(); // will print (13+1i)
cout<<endl;


cout << "Declaring a NullPtr" << endl;
p = nullptr;
printf("p = %p\n", p); // prints 000000


//Interview Question:
// what will happen when you try to dereference a nullptr which is not pointing to any memory address location
//Real newNumber = *p; // will thrown an error. you cannot.


/*
OverAll Notes summary:
&    <---   address of whatever comes in front   (Gets the Address)
*    <--- dereferencing the value being pointed by the pointer (Gets the value)
->   <--- arrow operator is being used when you want to work on the direct copy of the object
     the pointer is pointing to. you want access member function or the data members of the class or struct


return 0;
}
