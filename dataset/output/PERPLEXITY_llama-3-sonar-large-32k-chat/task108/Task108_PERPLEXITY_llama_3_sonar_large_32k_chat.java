// Java code using Java RMI
import java.rmi.*;
import java.rmi.server.*;

public interface MyInterface extends Remote {
    String getData() throws RemoteException;
    void setData(String data) throws RemoteException;
}

public class Task108_PERPLEXITY_llama_3_sonar_large_32k_chat extends UnicastRemoteObject implements MyInterface {
    public Task108_PERPLEXITY_llama_3_sonar_large_32k_chat() throws RemoteException {
        super();
    }

    public String getData() throws RemoteException {
        return "Hello from server!";
    }

    public void setData(String data) throws RemoteException {
        System.out.println("Received data from client: " + data);
    }
}

public class Server {
    public static void main(String[] args) throws Exception {
        Task108_PERPLEXITY_llama_3_sonar_large_32k_chat obj = new Task108_PERPLEXITY_llama_3_sonar_large_32k_chat();
        Naming.rebind("MyService", obj);
        System.out.println("Server ready");
    }
}