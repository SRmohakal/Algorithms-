# 🧠 Socket Programming in Python

**Socket Programming** allows two computers or processes to communicate with each other over a network.
A **socket** acts as an endpoint for sending and receiving data between two programs running on the same or different machines.

It is the foundation for many real-world applications such as:

* 🌐 Web servers and browsers
* 💬 Chat and messaging systems
* 📁 File transfer applications
* 🎮 Online multiplayer games

---

## What Is a Socket?

A **socket** is one endpoint of a two-way communication link between two programs.
It can be used to send and receive data over both **local** and **remote** networks.

---

## Socket Basics in Python

Python provides the built-in **`socket`** module, which supports all essential network operations for both **TCP** and **UDP** communication.

| Function          | Description                                                     |
| ----------------- | --------------------------------------------------------------- |
| `socket.socket()` | Create a socket object                                          |
| `bind()`          | Bind the socket to a specific IP address and port (server side) |
| `listen()`        | Wait for incoming connections                                   |
| `accept()`        | Accept a new client connection                                  |
| `connect()`       | Connect to a remote server (client side)                        |
| `send()`          | Send data through the socket                                    |
| `recv()`          | Receive data from the socket                                    |
| `close()`         | Close the socket connection                                     |

---

## How It Works

| Step | Server                                | Client               |
| ---- | ------------------------------------- | -------------------- |
| 1    | Creates socket and binds to IP & port | Creates socket       |
| 2    | Listens for incoming connections      | Connects to server   |
| 3    | Accepts connection                    | Sends data to server |
| 4    | Receives message and responds         | Receives reply       |
| 5    | Closes connection                     | Closes connection    |

---

## Example Applications

* **Simple client-server communication** – Send and receive messages.
* **Two-way chat system** – Enables interactive messaging between client and server.
* **File transfer system** – Send files from one machine to another.
* **Web server simulation** – Handle multiple client requests.

---

## Common Socket Types

| Type                  | Description                                 | Example Use                        |
| --------------------- | ------------------------------------------- | ---------------------------------- |
| **TCP (SOCK_STREAM)** | Reliable, connection-oriented communication | Chat, Web servers                  |
| **UDP (SOCK_DGRAM)**  | Fast, connectionless communication          | Video streaming, Online games, DNS |

---

## How to Run

1. Clone the repository:

   ```bash
   git clone https://github.com/<your-username>/SocketProgramming.git
   cd SocketProgramming
   ```

2. Run the **server** file first in one terminal.

3. Then, run the **client** file in another terminal to connect and communicate.

>  Note: Both should use the same host (e.g., `localhost`) and port number.

---

## Key Takeaways

* A **socket** is the foundation of all network communication.
* **TCP sockets** ensure reliability; **UDP sockets** provide speed.
* **Client-server architecture** is the core of most networking applications.
* Python’s `socket` module makes it simple to build both types.

---

## Author

**Shourov Roy**
B.Sc. in Computer Science Student
📍 Shahjalal University of Science and Technology, Bangladesh
🗓️ Year: 2025
📧 [shourovcsesust@gmail.com](mailto:your-email@example.com)
🌐 [https://github.com/SRmohakal](https://github.com/your-username)

---

## 🪪 License

This project is licensed under the **MIT License** — free for educational and learning purposes.

---
#OperatingSystem #Python #socket-programming #client-server #chat-application #computer-networks #OSProject
