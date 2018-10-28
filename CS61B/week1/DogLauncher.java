public class DogLauncher {
    public static void main(String[] args) {
        //declaration of a Dog variable
        Dog smallDog;

        //instantiation of the Dog class as a Dog object. This instantiation will be
        //collected by the garbage collector if we don't assign it to a variable
        new Dog(30);

        //instantiation and assignment
        smallDog = new Dog(5);

        //ideally, do all 3 at once, declaration, instantiation and assignment
        Dog pepper = new Dog(55);

        //invocation of Dog class's makeNoise method
        pepper.makeNoise();

        //creates an array of Dogs size 2, can only hold dogs, arrays in java are static
        //at this point the array is empty.
        Dog[] dogArray = new Dog[2];

        //put 2 dogs in the array
        dogArray[0] = new Dog(99);
        dogArray[1] = new Dog(8);

        //invocation
        dogArray[1].makeNoise();

        Dog d1 = new Dog(23);
        Dog d2 = new Dog(45);

        //maxDog is static method, we use it directly directly from the Dog class
        //not from an instance.
        Dog bigger = Dog.maxDog(d1,d2);
        //bigger dog makes sound, bigger is an instance, makeNoise method is nonstatic
        bigger.makeNoise();

        //if you really want to make maxDog a nonstatic method, you can only use it with an instance
        //but this is kinda weird, now pepper becomes the decider of which dogs are
        //bigger instead of the Great Almighty D.O.G. What happen if pepper dies or
        //disappear? Better make these types of methods static.
        //Dog bigger = pepper.maxDog(d1, d2);

        //calling a static variable, a property that all Dogs share
        //class name is the preferred way to call static variables
        System.out.println(Dog.binomen);
        System.out.println(pepper.binomen);

    }
}