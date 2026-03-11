import java.io.*;
import java.net.*;

public class Clientarp {
    public static void main(String args[]) {
        try {
            BufferedReader userInput = new BufferedReader(new InputStreamReader(System.in));

            Socket socket = new Socket("172.33.18.108", 5000);

            BufferedReader din = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            DataOutputStream dout = new DataOutputStream(socket.getOutputStream());

            System.out.println("Enter the Logical Address (IP): ");
            String ip = userInput.readLine();

            dout.writeBytes(ip + "\n");

            String mac = din.readLine();

            System.out.println("The Physical Address is: " + mac);

            socket.close();
        } 
        catch (Exception e) {
            System.out.println(e);
        }
    }
}