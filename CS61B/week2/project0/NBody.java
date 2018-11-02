public class NBody {

    //a method when given a textfile, return the radius of the universe, line #2
    //Nbody.readRadius(); static, called by class
    public static double readRadius (String file) {
        //the In class allows for file accessing
        In in = new In(file);
        //everytime to read() method is called, it reads one item, make sure to assign that value to the correct type
        //we really don't even need to store firstline, just need to read it to get to the next line
        int firstline = in.readInt();
        //radius information is on line 2
        double radius = in.readDouble();
        return radius;
    }

    //a method when given a textfile, return an array of planet objects
    public static Planet[] readPlanets(String file) {
        In in = new In(file);
        //get number of planets from file, line 1
        int numberOfPlanets = in.readInt();
        //create a Planet object array, the size comes from the text file
        Planet[] planets = new Planet[numberOfPlanets];
        //don't need this, but need to go to the next line
        double radius = in.readDouble();
        //loop through the number of planets
        for (int i = 0; i < numberOfPlanets; i++) {
            //line 3 and on
            double xxPos = in.readDouble();
            double yyPos = in.readDouble();
            double xxVel = in.readDouble();
            double yyVel = in.readDouble();
            double mass = in.readDouble();
            String imgFileName = in.readString();
            //call constructor and pass in data and put in the array we created earlier
            planets[i] = new Planet(xxPos, yyPos, xxVel, yyVel, mass, imgFileName);
        }
        return planets;
    }

    public static void main(String[] args) {
        //how long this animation will last, in millisecond
        double T = Double.parseDouble(args[0]);

        //time increment aka change in time
        double dt = Double.parseDouble(args[1]);

        //the source file
        String filename = args[2];

        double radius = readRadius(filename);

        //an array of planet objects
        Planet[] planets = readPlanets(filename);

        //set the scale so that it matches the radius of the universe
        StdDraw.setScale(-2 * radius, 2 * radius);

        //draw starfield.jpg as background use the stdDraw library
        StdDraw.picture(0, 0, "images/starfield.jpg");

        //drawing all planets
        for (int i = 0; i < planets.length; i++) {
            planets[i].draw();
        }

        //prevent flickering in animation
        StdDraw.enableDoubleBuffering();

        //discritize time, do a bunch of calculation at each time interval
        for (double time = 0; time <= T; time += dt) {

            double[] xForces = new double[planets.length];
            double[] yForces = new double[planets.length];

            for (int i = 0; i < planets.length; i++) {
                Planet p = planets[i];
                xForces[i] = p.calcNetForceExertedByX(planets);
                yForces[i] = p.calcNetForceExertedByY(planets);
            }

            for (int i = 0; i < planets.length; i++) {
                planets[i].update(dt, xForces[i], yForces[i]);
            }

            //draw background image
            StdDraw.picture(0, 0, "images/starfield.jpg");

            //draw all planets
            for (int i = 0; i < planets.length; i++) {
                    planets[i].draw();
            }

            //the animation
            StdDraw.show();
            StdDraw.pause(10);

            //printing the universe once the animation is over
            //time == T
            StdOut.printf("%d\n", planets.length);
            StdOut.printf(".2e\n", radius);
            for (int i = 0; i < planets.length; i++) {
                Planet p = planets[i];
                StdOut.printf("%11.4e %11.4e %11.4e %11.4e %11.4e %12s\n",p.xxPos, p.yyPos, p.xxVel, p.yyVel, p.mass, p.imgFileName);
            }
        }

    }
}