import requests

r=requests.get(url='http://www.weihhh.cn')
print(r.status_code)

r=requests.get(url='http://dict.baidu.com/s',params={'wd':'python'})
print(r.url)
print(r.text)