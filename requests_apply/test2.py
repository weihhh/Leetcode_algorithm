import requests
 
url = 'http://127.0.0.1:5000/upload'
files = {'file': open(r'C:\Users\weihao\Documents\GitHub\coding\test.py', 'rb')}
#files = {'file': ('report.jpg', open('/home/lyb/sjzl.mpg', 'rb'))}     #显式的设置文件名
 
r = requests.post(url, files=files)
print(r.text)