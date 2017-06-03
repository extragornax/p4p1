import os,sys
import socket, server.usage as usage, server.handle_client as handle_client
import threading
import multiprocessing

class server():

    def __init__(self, port):
        self.port = port
        self.log_file = open("/tmp/p4p1_server.log", "a")
        self.client = []
        self.client_data = dict()                                   # self.client_data[ip] = [ client, addr, is_active ]
        self.on = True
        self.prompt = '<p4p1 />'
        self.sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)

    def listen(self):
        self.sock.bind(("0.0.0.0", self.port))
        self.sock.listen(5)

    def accept(self, old):
        self.listen()
        while self.on:
            client, addr = self.sock.accept()
            self.client.append(addr[0])
            self.client_data[addr[0]] = [ client, addr]

    def close_connection(self):
        s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        s.connect(('127.0.0.1', self.port))
        s.close()

    def main(self, old=False):
        accept = threading.Thread(target=self.accept, args=(old, ))
        accept.start()
        while True:
            buf = raw_input(self.prompt)
            if buf == 'list':
                for i in self.client:
                    print i
            if "connect" in buf:
                b = buf.split(' ')
                if b[1] in self.client:
                    hd = handle_client.client_handler(self.client_data[b[1]][0], self.client_data[b[1]][1])
                    if not old:
                        hd.handle_client()
                    else:
                        hd.handle_old_client()
                else:
                    print "[!] Client non existant!"
            elif buf == 'exit':
                self.on = False
                self.close_connection()
                accept.join()
                break
            else:
                print "[!] Unknown command"

if __name__ == "__main__":
    s = server(4441)
    s.main()