import java.io.FileInputStream;
import java.io.IOException;
import java.sql.*;
import java.util.Properties;

public class JDBCExample {

    public static void main(String[] args) {
        String url = "jdbc:mysql://localhost:3306/add_your_database_name";
        String username = "add_your_username";
        String password = "add_your_password";

        Connection connection = null;
        Statement statement = null;
        ResultSet resultSet = null;

        try {
            connection = DriverManager.getConnection(url, username, password);
            statement = connection.createStatement();

            String selectQuery = "SELECT * FROM students";
            resultSet = statement.executeQuery(selectQuery);

            // Print header
            System.out.printf("%-15s %-15s %-15s %-10s %-25s %-15s%n", 
                "First Name", "Last Name", "Date of Birth", "Gender", "Email", "Phone Number");
            System.out.println("---------------------------------------------------------------------------");

            // Print each row
            while (resultSet.next()) {
                String firstName = resultSet.getString("first_name");
                String lastName = resultSet.getString("last_name");
                String dob = resultSet.getString("dob");
                String gender = resultSet.getString("gender");
                String email = resultSet.getString("email");
                String phoneNumber = resultSet.getString("phone_number");

                System.out.printf("%-15s %-15s %-15s %-10s %-25s %-15s%n", 
                    firstName, lastName, dob, gender, email, phoneNumber);
            }
        } catch (SQLException se) {
            se.printStackTrace();
        } finally {
            try {
                if (resultSet != null) resultSet.close();
                if (statement != null) statement.close();
                if (connection != null) connection.close();
            } catch (SQLException se) {
                se.printStackTrace();
            }
        }
    }

    public static Properties loadProperties(String filePath) {
        Properties properties = new Properties();
        try (FileInputStream fileInputStream = new FileInputStream(filePath)) {
            properties.load(fileInputStream);
        } catch (IOException e) {
            e.printStackTrace();
        }
        return properties;
    }
}
