//what is the deal with: public static void main(String[] args) ?
//well this is a public static method
//it returns nothing thus void
//main is the name of the method
//(String[] args) is the command line arguments

public class ArgsDemo {
    /** prints out the 0th command line argument. */
    //call: java ArgsDemo khoa, should print khoa
    public static void main(String[] args) {
        System.out.println(args[0]);
    }
}
