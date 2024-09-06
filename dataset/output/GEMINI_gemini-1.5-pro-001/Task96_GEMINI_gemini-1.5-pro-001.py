import socket

# Create a socket object
serversocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Get the local machine name
host = socket.gethostname()

# Reserve a port for your service
port = 5000

# Bind to the port
serversocket.bind((host, port))

# Queue up to 5 requests
serversocket.listen(5)

while True:
    # Establish a connection with a client
    clientsocket,addr = serversocket.accept()

    print("Got a connection from %s" % str(addr))

    while True:
        # Receive data from the client
        data = clientsocket.recv(1024)

        if not data:
            break

        # Echo back the data to the client
        clientsocket.send(data)

    # Close the connection with the client
    clientsocket.close()