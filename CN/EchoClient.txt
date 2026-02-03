package javaapplication4;

import java.io.*;
import java.net.*;
import java.util.Scanner;

public class EchoClient {

    public static void main(String[] args) {
        String serverAddress = "localhost";
        int port = 5000;

        try {
            // 1. Connect to server
            Socket socket = new Socket(serverAddress, port);
            System.out.println("Connected to server.");

            // 2. Input and Output streams
            BufferedReader in = new BufferedReader(
                    new InputStreamReader(socket.getInputStream()));
            PrintWriter out = new PrintWriter(socket.getOutputStream(), true);

            // 3. Read user input
            Scanner scanner = new Scanner(System.in);
            System.out.print("Enter message: ");
            String message = scanner.nextLine();

            // 4. Send message to server
            out.println(message);

            // 5. Receive echo
            String response = in.readLine();
            System.out.println("Echo from server: " + response);

            // 6. Close connection
            socket.close();

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
