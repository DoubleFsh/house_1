import socket

s = socket.socket()
ip = str(input())
#定义一个数组来存储套接字所指向的ports
ports = [21,2,1,1333,212]
for i in range(5):
    scan_port = ports[i]
    try:
        s.connect((ip,scan_port))
        s.send("Fuck")
        ifmtions = str(s.recv(2048))
        print (ifmtions)
        print("\n")
    except Exception as b:
        print(b)
        print("\n")
