from webbot import Browser 
import time
web = Browser()
web.go_to('google.com') 
web.click('Sign in')
web.type('4079tsui@gmail.com' , into='Email')
web.click('NEXT' , tag='span')
time.sleep(5)
web.type('hk--40796498' , into='Password' , id='passwordFieldId') # specific selection
web.click('NEXT' , tag='span') # you are logged in ^_^#
time.sleep(5)
response=web.get_page_source()
print(response)
web.quit()
