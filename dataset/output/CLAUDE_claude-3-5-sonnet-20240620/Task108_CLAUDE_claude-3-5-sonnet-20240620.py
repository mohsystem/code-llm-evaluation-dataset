
import Pyro4

@Pyro4.expose
class RemoteObject:
    def __init__(self):
        self.value = 0

    def get_value(self):
        return self.value

    def set_value(self, new_value):
        self.value = new_value

    def increment(self):
        self.value += 1

def main():
    Pyro4.Daemon.serveSimple(
        {
            RemoteObject: "remote_object"
        },
        ns=False,
        host="localhost",
        port=9090
    )

if __name__ == "__main__":
    main()
