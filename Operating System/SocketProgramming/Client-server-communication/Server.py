import socket

#creating server socket
server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

#binding to localhost and port
server.bind(("localhost", 12345))

#listening for connection
server.listen(1)
print("Server is listining on port 12345...")

#Accepting connection
conn, addr = server.accept()

#receiving msg
message = conn.recv(1024).decode()
print(f"Cliest says: {message}")

#sending response to the client
conn.send("Hello from Server!".encode())

#close connection
conn.close()

#close server
server.close()

#NOTE: First run server.py then run client.py in different different window
