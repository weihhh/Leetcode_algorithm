import socket,asyncio,queue,re
import urllib.parse

    
class Crawler:
    def __init__(self,roots,max_redirect=10,max_tries=4,*,loop=None):
        self.loop=loop or asyncio.get_event_loop() 
        self.roots=roots
        self.max_redirect = max_redirect
        self.max_tries = max_tries
        self.q_default=queue.Queue()#不是asycio中的queue,maxsize默认为0，表示无限


    def default_fetch(self,url,host,port):
            sock=socket.socket()
            sock.connect((host,port or 80))
            request='GET {} HTTP/1.0\r\nHost: xkcd.com\r\n\r\n'.format(url)
            sock.send(request.encode('ascii'))
            response=b''
            chunk=sock.recv(4096)
            while chunk:
                response+=chunk
                chunk=sock.recv(4096)
            links=self.parse_link(response)
            for link in links:
                self.q_default.put((link,self.max_redirect))#put()有两个参数，item必须，block可选，是否阻塞，不阻塞则产生异常
            return response 
            
                
            # print(response.decode('utf-8'))
        # fetch('www.weihhh.cn/')
    def begin_default_claw(self):
        self.q_default.put(('www.weihhh.cn',self.max_redirect))
        i=1000
        while i>0:
            i-=1
            url,max_redirect=self.q_default.get()
            parts=urllib.parse.urlparse(url)
            host,port=urllib.parse.splitport(parts.netloc)
            if not host:
                continue
            response=self.default_fetch(url,host,port)
            if response:
                print('ok')


    def handle_response(response):
        response=b''

    def parse_link(sefl,response):
        
        re.findall(r'''(?i)href=["']([^\s"'<>]+)''',text)
