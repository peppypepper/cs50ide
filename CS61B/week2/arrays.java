

//declaration, this creates a 64 bit box intended only for storing a reference/pointer to an int array.
//No object is instantiated yet. This box is undefined.
int[] a;

//instantiates a new Object, in this case an int array.
//object is anonymous due to lack of assignment.
//this array object is unusable because we can't get to it.
//We don't know where it lives in memory. It doesn't have a reference.
new int[]{1,2,45,6};


//arrays are objects, instantiate using the new keyword
//everything together: declaration, instantiation and assignemnt.
int[] x = new int[]{1,2,35,6};
//or
//creates array containing 3 int boxes (32x3=96bits total), each container gets a default value
y = new int[3];
//or
y = new int[]{2,3,4,5};
//or
//can omit the new keyword if you are also declaring a variable
int[] w = {4,5,6,7};

//see arraycopy image, because arrays are passed by reference. You might want to protect the original array
//the arraycopy method let you make a copy and work with the copy so you don't damange the original.