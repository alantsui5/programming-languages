import requests
from bs4 import BeautifulSoup

#globals
parent_link = "https://www.shikoto.com"

def get_title():
	#Storage
	list1 = {}

	#Logic
	r=requests.get("https://www.shikoto.com/articles/59460.html")
	soup = BeautifulSoup(r.text,features="html.parser")
	for a in soup.select("div > .article .row > .col-lg-12 a[href]"):
		if not a.has_attr("data-toggle"):
			print(a.text)
			list1[a.text]=a.attrs['href']
	return list1

def get_essay(links):
	#Storage

	#Logic
	r=requests.get(parent_link+links)
	soup = BeautifulSoup(r.text,features="html.parser")
	for a in soup.select(" .content > .row > .col-lg-12 > .chapter-container > .chapter-content-wrapper > .content"):
		if a.div:
			continue
		else:
			print(a.text)

get_essay('/articles/59460/59462.html')
#titles = get_title()
