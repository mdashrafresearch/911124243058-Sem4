package pkg3b;

import java.io.*;
import java.net.*;

public class TcpChatClient {

    public static void main(String[] args) {
        try {
            Socket socket = new Socket("localhost", 4000);

            BufferedReader fromServer = new BufferedReader(
                    new InputStreamReader(socket.getInputStream()));
            PrintWriter toServer = new PrintWriter(
                    socket.getOutputStream(), true);

            BufferedReader fromUser = new BufferedReader(
                    new InputStreamReader(System.in));

            String msg;

            while (true) {
                System.out.print("Client: ");
                msg = fromUser.readLine();
                toServer.println(msg);

                if (msg.equalsIgnoreCase("end"))
                    break;

                System.out.println("Server: " + fromServer.readLine());
            }

            socket.close();

        } catch (Exception e) {
            System.out.println(e);
        }
    }
}
