# MINITALK
Minitalk is a simple communication program implemented in C. It consists of two components:

Server: Listens for incoming messages and displays them upon receipt.
Client: Sends messages to the server.
This project demonstrates inter-process communication (IPC) using Unix signals.

## USAGE
Clone the Repository:

```bash
git clone https://github.com/jasonmgl/minitalk.git
```
Navigate to the Directory:

```bash
cd minitalk
```
Compile the Program:

Use the provided Makefile to compile both the server and client:

```bash
make
```
This will generate two executables: server and client.

Run the Server:

Start the server to begin listening for messages:

```bash
./server
```
The server will display its process ID (PID), which is needed by the client to send messages.

Run the Client:

In a separate terminal, use the client to send a message to the server:

```bash
./client [server_pid] "Your message here"
```
Replace [server_pid] with the PID displayed by the server and "Your message here" with the message you wish to send.

## DEPENDENCIES
- Compiler: Requires a C compiler like gcc.
- Make: Utilizes make for building the program.
- Operating System: Designed for Unix-like systems that support signal-based IPC.

## DESCRIPTIONS
Server:

The server program initializes by retrieving its PID and displaying it. It then enters an infinite loop, waiting for incoming signals. Upon receiving a signal, it decodes the message sent by the client and displays it.

Client:

The client program takes two arguments: the server's PID and the message to be sent. It converts the message into a series of signals and sends them to the server using the specified PID.
