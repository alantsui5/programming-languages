import requests
from bs4 import BeautifulSoup
r=requests.get("https://www.shikoto.com/articles/59460.html")
soup = BeautifulSoup(r.text,features="html.parser")
for a in soup.select("div > .article .row > .col-lg-12 a[href]"):
		if not a.has_attr("data-toggle"):
			print(a.text)
