
public class Planet {
    //some instance variables
    public double xxPos;
    public double yyPos;
    public double xxVel;
    public double yyVel;
    public double mass;
    public String imgFileName;

    //constructor
    public Planet(double xxPos, double yyPos, double xxVel, double yyVel, double mass, String imgFileName) {
        //used the same name xxPos as the instance varible, need to use the this. keyword
        //looks nice, this is probably the way to go
        this.xxPos = xxPos;
        this.yyPos = yyPos;
        this.xxVel = xxVel;
        this.yyVel = yyVel;
        this.mass = mass;
        this.imgFileName = imgFileName;
    }

    //copy constructor
    //this one takes in a planet object and initialize/make a copy of the planet
    public Planet(Planet p) {
        this.xxPos = p.xxPos;
        this.yyPos = p.yyPos;
        this.xxVel = p.xxVel;
        this.yyVel = p.yyVel;
        this.mass = p.mass;
        this.imgFileName = p.imgFileName;

    }

    //a method that calculates distance between two planets
    //samh.calcDistance(rocinante)
    //take one planet and return a double equal to the distance
    //between the supplied planet and the one that is doing the calculation.
    //this is the "r" from the equations
    //nonstatic, will be called by an instance planet
    //return a double
    public double calcDistance(Planet p) {
        double dx = p.xxPos - this.xxPos;
        double dy = p.yyPos - this.yyPos;
        double r = Math.sqrt(dx*dx + dy*dy);
        return r;
    }
    //a method takes in a planet, return a double, describing
    //the force exerted on this planet by the given planet
    //samh.calcForceExertedBy(rocinante), nonstatic
    //this is F = F1 = F2 from the equations, pairwise force
    public double calcForceExertedBy(Planet p) {
        final double G = 6.67e-11;
        double r = this.calcDistance(p);
        double F = (G * p.mass * this.mass) / (r*r);
        return F;

    }
    //samh.calcForceExertedByX(rocinante)
    //this is Fx, check for signs
    public double calcForceExertedByX(Planet p) {
        double F = this.calcForceExertedBy(p);
        double r = this.calcDistance(p);
        double dx = p.xxPos - this.xxPos;
        double Fx = F * dx / r;
        return Fx;
    }
    //samh.calcForceExertedByY(rocinante)
    //this is Fy, check for signs
    public double calcForceExertedByY(Planet p) {
        double F = this.calcForceExertedBy(p);
        double r = this.calcDistance(p);
        double dy = p.yyPos - this.yyPos;
        double Fy = F * dy / r;
        return Fy;
    }
    //take in an array of planets and calculate the Fnetx
    //exerted by all planets in that array upon the current planet
    //Planet[] allPlanets = {samh, rocinante, aegir};
    //samh.calcNetForceExertedByX(allPlanets);
    //use samh.equals(samh) which return true to avoid planet exert forces on itself
    public double calcNetForceExertedByX(Planet[] allPlanets) {
        double Fnetx = 0;
        //loop and add all the Fx except for the planet calling use .equals method
        for (int i = 0; i < allPlanets.length; i++) {
            if (this.equals(allPlanets[i]) != true) {
                Fnetx += this.calcForceExertedByX(allPlanets[i]);
            }
        }
        return Fnetx;
    }

    public double calcNetForceExertedByY(Planet[] allPlanets) {
        double Fnety = 0;
        //loop and add all the Fx except for the planet calling use .equals method
        for (int i = 0; i < allPlanets.length; i++) {
            if (this.equals(allPlanets[i]) != true) {
                Fnety =  Fnety + this.calcForceExertedByY(allPlanets[i]);
            }
        }
        return Fnety;
    }

    //a method to determine how much the forces exerted on the planet will cause that planet to
    //accelerate and the resulting change in the planet's velocity and position in a period of time.
    //samh.update(0.005, 10, 3), (time, fx, fy), what would be the planet's final velocity and position
    public void update(double dt, double fX, double fY) {

    //calculate acceleration using provided fx and fy
    double ax = fX / this.mass;
    double ay = fY / this.mass;
    //calculate new velocity using current velocity, time and acceleration from step 1
    this.xxVel = this.xxVel + dt * ax;
    this.yyVel = this.yyVel + dt * ay;
    //calculate new position using current position, time and velocity from step 2
    this.xxPos = this.xxPos + dt * this.xxVel;
    this.yyPos = this.yyPos + dt * this.yyVel;
    }

    //a method, planet be able to draw itself at its current position
    //somePlanet.draw()
    public void draw() {
        //draw one planet using StdDraw API
        StdDraw.picture(this.xxPos, this.yyPos, this.imgFileName);
    }
}