import requests
#post statement with cookies
session=requests.Session()
data = {'firstname':'Alan','lastname':'Tsui'}
r=session.post('http://pythonscraping.com/pages/files/processing.php',data=data)
r=session.get('http://pythonscraping.com/pages/files/processing.php')
print(r.text)