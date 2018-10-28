public class ArgsSum {
    /** sum of command line arguments. */
    public static void main(String[] args) {
        int N = args.length;
        int i = 0;
        int sum = 0;
        while (i < N) {
            sum = sum + Integer.parseInt(args[i]);
            i++;
        }
        System.out.println(sum);
    }
}