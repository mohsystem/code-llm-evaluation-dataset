import socket
import pickle

HOST = 'localhost'
PORT = 65432

class DataObject:
    def __init__(self, value):
        self.value = value

    def get_value(self):
        return self.value

    def set_value(self, new_value):
        self.value = new_value

def handle_request(conn, data_object):
    data = conn.recv(1024)
    command, *args = pickle.loads(data)

    if command == 'GET':
        conn.sendall(pickle.dumps(data_object.get_value()))
    elif command == 'SET':
        data_object.set_value(args[0])
        conn.sendall(pickle.dumps('Value updated'))
    else:
        conn.sendall(pickle.dumps('Invalid command'))

def main():
    data_object = DataObject(10)

    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.bind((HOST, PORT))
        s.listen()
        conn, addr = s.accept()
        with conn:
            print(f"Connected by {addr}")
            while True:
                handle_request(conn, data_object)

if __name__ == '__main__':
    main()