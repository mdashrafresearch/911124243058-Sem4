package pkg3b;

import java.io.*;
import java.net.*;

public class TcpChatServer {

    public static void main(String[] args) {
        try {
            ServerSocket server = new ServerSocket(4000);
            System.out.println("Server started...");

            Socket client = server.accept();
            System.out.println("Client connected");

            BufferedReader fromClient = new BufferedReader(
                    new InputStreamReader(client.getInputStream()));
            PrintWriter toClient = new PrintWriter(
                    client.getOutputStream(), true);

            BufferedReader fromUser = new BufferedReader(
                    new InputStreamReader(System.in));

            String msg;

            while (true) {
                msg = fromClient.readLine();
                if (msg.equalsIgnoreCase("end"))
                    break;

                System.out.println("Client: " + msg);
                System.out.print("Server: ");
                toClient.println(fromUser.readLine());
            }

            client.close();
            server.close();
            System.out.println("Connection closed");

        } catch (Exception e) {
            System.out.println(e);
        }
    }
}
