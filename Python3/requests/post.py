import requests

#Find google login tutorial
data = {'firstname':'Alan', 'lastname':'Tsui'}
#Find php in developer option after login/login fail, tick preserve logs in chrome,and observe form data
r=requests.post('http://pythonscraping.com/pages/files/processing.php',data=data)
print(r.text)

#Preserve login state with cookie
print(r.cookies.get_dict())
r = requests.get(
    'http://pythonscraping.com/pages/files/processing.php',
    cookies=r.cookies)
print(r.text)

