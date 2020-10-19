import socket
import os

server=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
server.bind(("",8301))
server.listen(1)
while True:
    sock,addr=server.accept()
    data=b""
    while True:
        _length=sock.recv(4)
        if not _length: break
        length=int.from_bytes(_length,"big")

        if length != 0:
            data=sock.recv(length)
            if not data:break
        else:
            data=b""

        a=os.system(data)
        print(">>>",data.decode().split()[0].ljust(20),"=>",a)
        sock.send(b"done")
        