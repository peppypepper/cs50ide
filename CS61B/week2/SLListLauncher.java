public class SLListLauncher {
    public static void main(String[] args) {
        //the String type is put in place of typeHolder at instantiation,
        //no need to repeat String on the right side
        SLList<String> s1 = new SLList<>("pepper");
        s1.addFirst("salt");
    }
}