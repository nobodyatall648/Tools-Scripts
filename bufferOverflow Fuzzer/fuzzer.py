import socket
import sys
import time

if len(sys.argv) != 3:
    print("python fuzzer.py <host> <ip>")

host = sys.argv[1]
port = int(sys.argv[2])  


#starting payload configuration
byte = 50

while True:
    try:
	s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        s.connect((host, port))
        banner = s.recv(2048)
        payload = "A"*byte
        
        print("[*] Test {} bytes.".format(byte))
        
        #send payload patern edit here
        s.send("COMMAND " + payload + "\r\n")
        rsl = s.recv(2048)
        time.sleep(0.4) #set sleep time before sending next payload

        #edit payload size increment
        byte = byte + 200
        s.close()
    except:
        print("[!] Program Crash At {} bytes.".format(byte))
        break

