import socket

#creating client socket
client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

#connect to the server
client.connect(("localhost", 12345))

#sending msg to server
client.send("Hello server!".encode())

#Receiving response from server
response = client.recv(1024).decode()
print(f"Server replied: {response}")

#closeing client
client.close()
