import socket

sock=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
sock.connect(("127.0.0.1",8301))

def send(data:str):
    global sock
    tmp=b""
    tmp+=len(data).to_bytes(4,"big")
    tmp+=data.encode()
    sock.send(tmp)

    msg=sock.recv(4)
    if msg != b"done":
        print("Unknown Reply Message",msg)

send("clear")
send("rm notepadsh")
send("make")
send("LD_LIBRARY_PATH=/usr/local/lib ./notepadsh")
sock.close()