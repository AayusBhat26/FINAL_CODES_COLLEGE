package jdbc;
import java.io.FileInputStream;
import java.io.IOException;
import java.sql.*;
import java.util.Properties;

public class JDBCExample {
    
    
    public static void main(String[] args) {
        // Properties properties = loadProperties("config.properties");
        String url = ("mysql://localhost:3306/university_masters");
        String username = ("root");
        String password =("root");

        Connection connection = null;
        Statement statement = null;
        ResultSet resultSet = null;

        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            connection = DriverManager.getConnection(url, username, password);
            statement = connection.createStatement();

            // String insertQuery = "INSERT INTO students (name, age, grade) VALUES ('Aayush Kumar', 21, 'A')";
            // int rowsInserted = statement.executeUpdate(insertQuery);
            // if (rowsInserted > 0) {
            //     System.out.println("Record inserted successfully.");
            // }
            String selectQuery = "SELECT * FROM students";
            resultSet = statement.executeQuery(selectQuery);

            // System.out.println("ID | Name          | Age | Grade");
            while (resultSet.next()) {
                // int id = resultSet.getInt("id");
                // String name = resultSet.getString("name");
                // int age = resultSet.getInt("age");
                // String grade = resultSet.getString("grade");
                // System.out.println(id + " | " + name + " | " + age + " | " + grade);
                System.out.println(resultSet);
            }
        } catch (SQLException se) {
            se.printStackTrace();
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
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
