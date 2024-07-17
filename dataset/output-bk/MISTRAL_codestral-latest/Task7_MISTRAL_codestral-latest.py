# Client
import socket

s = socket.socket()
port = 4999

s.connect(('127.0.0.1', port))

username = input("Enter username: ")
password = input("Enter password: ")

message = username + "," + password
s.send(message.encode())

s.close()

# Server
import socket

s = socket.socket()
print("Socket successfully created")

port = 4999

s.bind(('', port))
print("socket binded to %s" %(port))

s.listen(5)
print("socket is listening")

while True:
   c, addr = s.accept()
   print('Got connection from', addr)

   message = c.recv(1024).decode()
   print(message)
   # Authenticate credentials here

   c.close()