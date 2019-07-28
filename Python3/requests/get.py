import requests
param = {"q":"insta"}
r=requests.get('http://www.google.com/search',params=param)
print(r.url)