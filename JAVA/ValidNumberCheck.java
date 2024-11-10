public class ValidNumberCheck {
    
    // Method to check if the string is a valid integer or double
    public static void checkValidNumber(String[] arr) {
        for (String str : arr) {
            try {
                // Try parsing the string as an integer
                Integer.parseInt(str);
                System.out.println(str + " is a valid integer.");
            } catch (NumberFormatException e1) {
                try {
                    // Try parsing the string as a double
                    Double.parseDouble(str);
                    System.out.println(str + " is a valid double.");
                } catch (NumberFormatException e2) {
                    // If both parsing attempts fail, it is neither integer nor double
                    System.out.println(str + " is not a valid integer or double.");
                }
            }
        }
    }

    public static void main(String[] args) {
        System.out.println("\n\n\n");
        String[] arr = {"100", "10.2", "5.hello", "100hello"};
        checkValidNumber(arr);
        System.out.println("\n\n\n");
    }
}
