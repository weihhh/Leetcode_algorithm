import urllib.parse,re

def lenient_host(host):
    parts = host.split('.')[-2:]
    print(parts)
    return ''.join(parts)



parts = urllib.parse.urlparse('https://docs.python.org/3.5/library/asyncio-queue.html')#url字符串分解为6个元素，以元祖的形式返回,scheme://netloc/path;parameters?query#fragment,返回的对象还包含了一些属性：username、password、hostname、port.
host, port = urllib.parse.splitport(parts.netloc)
print(parts,host,port)
print(lenient_host(host))
print('' or 'shh')

if re.match(r'\A[\d\.]*\Z', '192.168.1.4:80'):
    print('ok')
else:
    print('nok')