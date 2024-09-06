
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.UnicastRemoteObject;
import java.rmi.RemoteException;
import java.rmi.Remote;

interface RemoteObject extends Remote {
    int getValue() throws RemoteException;
    void setValue(int newValue) throws RemoteException;
    void increment() throws RemoteException;
}

class RemoteObjectImpl implements RemoteObject {
    private int value = 0;

    public int getValue() throws RemoteException {
        return value;
    }

    public void setValue(int newValue) throws RemoteException {
        value = newValue;
    }

    public void increment() throws RemoteException {
        value++;
    }
}

public class Task108_CLAUDE_claude_3_5_sonnet_20240620 {
    public static void main(String[] args) {
        try {
            RemoteObjectImpl obj = new RemoteObjectImpl();
            RemoteObject stub = (RemoteObject) UnicastRemoteObject.exportObject(obj, 0);

            Registry registry = LocateRegistry.createRegistry(1099);
            registry.bind("RemoteObject", stub);

            System.out.println("Server ready");
        } catch (Exception e) {
            System.err.println("Server exception: " + e.toString());
            e.printStackTrace();
        }
    }
}
