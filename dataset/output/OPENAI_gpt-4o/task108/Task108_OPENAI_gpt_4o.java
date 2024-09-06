// Java Remote Object Manipulation Server (example)
import java.rmi.*;
import java.rmi.server.*;
import java.rmi.registry.*;

public class Task108_OPENAI_gpt_4o extends UnicastRemoteObject implements RemoteObjectInterface {
    private int value;

    public Task108_OPENAI_gpt_4o() throws RemoteException {
        super();
        value = 0;
    }

    public String set_value(int value) throws RemoteException {
        this.value = value;
        return "Value set to " + this.value;
    }

    public int get_value() throws RemoteException {
        return value;
    }

    public static void main(String[] args) {
        try {
            LocateRegistry.createRegistry(1099);
            Task108_OPENAI_gpt_4o obj = new Task108_OPENAI_gpt_4o();
            Naming.rebind("RemoteObject", obj);
            System.out.println("Server is running...");
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}

interface RemoteObjectInterface extends Remote {
    String set_value(int value) throws RemoteException;
    int get_value() throws RemoteException;
}