//static vs non static methods
//each of them has different uses.

//non static methods like Dog.makeNoise() can utilize my provided variables


//static methods, some classes are never instantiated
x = Math.round(4.6);
//you would not
Math m = new Math();
x = m.round(4.6);

//sometimes, classes may have a mix of static and nonstatic methods
public static Dog maxDog(Dog d1, Dog d2) {
    if (d1.weightInPounds > d2.weightInPounds) {
        return d1;
    }
    return d2;
}
