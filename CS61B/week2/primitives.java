//there are 8 java primitive types: byte, short, int (32bits), long, float, double (64bits), boolean, char
//everything else are reference types: arrays, dogs, planets, objects,...work by pointers or reference, in memory
//java allocates 64bits for the addresses of these objects. The newly allocated memory can either be undefined or null or
//contain an address. Depends on how the box was declared. Undefined and null are not the same thing.

//parameters passing for primitives simply copy the bits to the new scope. This is "pass by value" and does
//not affect the original variable in the orgininal function.


public class primitives {
    public static void main(String[] args) {
        //make a new Walrus using the constructor, provide weight and tuskSize
        Walrus walrus = new Walrus(3500, 10.5);
        int x = 9;
        doStuff(walrus, x);
        System.out.println(walrus.weight);
        System.out.println(x);
    }
    public static void doStuff(Walrus W, int x) {
        W.weight = W.weight - 1100;
        x = x - 5;
    }
}

//what will print? Does walrus weight or x change? does doStuff affect the main function?
//when calling doStuff, we create 2 new memory allocations.
//one will copy the memory address of walrus aka point to the same walrus. 2 pointers to the same object.
//the other allocation will copy x = 9 to its memory.
//when weight - 100 in doStuff, we change the walrus at its location and thus changing the walrus in the main function
//when x - 5 in doStuff, we change the x in doStuff, now it's 4. But the original copy in the main function is unchanged.
//passing parameters for primitives to functions do not affect the original copy
//passing parameters for references to functions affect the original copy






