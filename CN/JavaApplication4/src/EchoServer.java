package javaapplication4;

import java.io.*;
import java.net.*;

public class EchoServer {

    public static void main(String[] args) {
        int port = 5000;

        try {
            // 1. Create ServerSocket
            ServerSocket serverSocket = new ServerSocket(port);
            System.out.println("Echo Server started on port " + port);
            System.out.println("Waiting for client...");

            // 2. Accept client connection
            Socket clientSocket = serverSocket.accept();
            System.out.println("Client connected!");

            // 3. Input and Output streams
            BufferedReader in = new BufferedReader(
                    new InputStreamReader(clientSocket.getInputStream()));
            PrintWriter out = new PrintWriter(clientSocket.getOutputStream(), true);

            // 4. Read from client
            String message = in.readLine();
            System.out.println("Received from client: " + message);

            // 5. Echo back
            out.println(message);

            // 6. Close connections
            clientSocket.close();
            serverSocket.close();
            System.out.println("Server closed.");

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
