public class Dog {
    //instance variable. Can have as many of these as you want.
    //non static, we expect this variable to change with each dog instance
    public int weightInPounds;

    //constructor. Determines how to instantiate the class. Main job is to set instance
    //variables but you don't have to set all of them.
    public Dog(int w) {
        weightInPounds = w;
    }

    //non static method aka instance method. If the method is going to be invoked by an instance
    //of the class, then it should be non-static. If the method needs to use "my instance variables"
    //the method should be non-static
    public void makeNoise() {
        if (weightInPounds < 10) {
            System.out.println("yipyip");
        } else if (weightInPounds < 30) {
            System.out.println("wooffwooff");
        } else {
            System.out.println("aarrrroooooffff");
        }
    }

    //a method to compare 2 dogs, a static method, return type Dog
    //why static? because we wil only call this method on the Dog class itself
    //not an instance of the class. Dog bigger = Dog.maxDog(d1,d2)
    public static Dog maxDog(Dog d1, Dog d2) {
        if (d1.weightInPounds > d2.weightInPounds) {
            return d1;
        }
        return d2;
    }

    //we can also have static variables. Something that all Dogs share
    public static String binomen = "Canis familiaris";

}