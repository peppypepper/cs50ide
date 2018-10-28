public class LeapYear {
    /** check if a year is a leap year or not */
    public static boolean isLeapYear(int year) {
        //invalid before 1583
        assert year > 1583;
        return (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));

    }

    public static void main(String[] args) {
        int year = Integer.parseInt(args[0]);
        if (LeapYear.isLeapYear(year) == true) {
            System.out.println(year + " is a leap year.");
        } else {
            System.out.println(year + " is not a leap year.");
        }
    }
}