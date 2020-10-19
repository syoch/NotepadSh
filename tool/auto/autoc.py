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
send("rm -dR dest")
send("mkdir dest")
send("rm -dR lib/py")
send("mkdir lib/py")
send("mkdir lib/py/collections")
send("python3 conv.py -d tool/libs -o lib/py -b")
send("python3 conv.py -d tool/libs/collections -o lib/py/collections -b")
send("python3 conv.py -f conv.py")
send("g++ -I lib -I lib/py -I lib/builtins dest/conv.cpp -o conv")
sock.close()