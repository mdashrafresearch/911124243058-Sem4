import java.io.*;
import java.net.*;

public class Serverarp {

    public static void main(String args[]) {

        try {
            ServerSocket server = new ServerSocket(5000);
            System.out.println("Server Started...");

            Socket socket = server.accept();
            System.out.println("Client Connected");

            BufferedReader din = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            DataOutputStream dout = new DataOutputStream(socket.getOutputStream());

            String ip[] = {"165.165.80.80", "165.165.79.1"};
            String mac[] = {"6A:08:AA:C2", "8A:BC:E3:FA"};

            while (true) {
                String clientIP = din.readLine();

                for (int i = 0; i < ip.length; i++) {
                    if (clientIP.equals(ip[i])) {
                        dout.writeBytes(mac[i] + "\n");
                        break;
                    }
                }
            }
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}