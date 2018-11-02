
public class TestPlanet {
    //test pairwise force between 2 planets
    public static void main(String[] args) {
        checkPairwise();
    }

    public static void checkPairwise() {
    System.out.println("checking the forth derivatives...");
    Planet pepper = new Planet(1,0,0,0,10, "mars.gif");
    Planet thao = new Planet(3,3,0,0,5, "squirrel.gif");
    double F = pepper.calcForceExertedBy(thao);
    System.out.println("F should be around: 2.57e-10 N");
    System.out.println("you got " + F + " N");
    }
}