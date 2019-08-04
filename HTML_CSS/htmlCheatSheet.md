# Free Code Camp HTML Cheatsheet
_Free Code Camp Curriculum_<br>
__regex included__

1. Headers
```html
<h[1-6]>Head[1-6]</h[1-6]>
```
2. Pragraph
```html
<p></p>
```
3. Commenting
```html
<!--Comment-->
```

4. Main content
```html
<main>Main Content</main>
```

5. Footer (Template WIP)
```html
<footer>Footer</Footer>
```

6. Navigation Bar
```html
<nav>
    <a href="title1">Title1</a>
    <a href="title2">Title2</a>
    <a href="title3">Title3</a>
    <a href="title4">Title4</a>
</nav>
```

7. Article (Template WIP)
```html
<article>Article</article>
```

8. Section (Template WIP)
```html
<section>Article</section>
```

9. Image (Template WIP)
```html
<img src="https://www.your-image-source.com/your-image.jpg">
```

10. Links
```html
<a href="links1">links1</a>
<!--Internal links-->
<a href="#contacts-header">Contacts</a>
<!-- Dead links-->
<a href="#">Contacts</a>
```

11. List
```html
<!-- Unordered List-->
<ul>
    <li>milk</li>
    <li>cheese</li>
</ul>
<!-- Unordered List-->
<ol>
    <li>milk</li>
    <li>cheese</li>
</ol>
```

## Forms
12. Text Field field
```html
<!-- text field-->
<input type="text">
<!-- With placeholder text-->
<input type="text" placeholder="this is placeholder">
<!--Compulsory field-->
<input type="text" required>
```

13. Simple Form
```html
<form action="/url-where-you-want-to-submit-form-data">
<input type="text" placeholder="this is placeholder">
<button type="submit">this button submits the form</button>
</form>
```
14. Radio Button
```html
<!-- Cehcked by default-->
<label> 
  <label for="indoor"> <input id="indoor" type="radio" name="indoor-outdoor" checked>Indoor </label>
  <label for="outdoor"> <input id="outdoor" type="radio" name="indoor-outdoor">Indoor </label> 

</label>
```

15. CheckBox
```html
<!-- Cehcked by default-->
<label for="loving" ><input id="loving" type="checkbox" name="personality" checked> Loving</label>
<label for="cute"><input id="cute" type="checkbox" name="personality"> Cute</label>
<label for="active"><input id="active" type="checkbox" name="personality"> Active</label>
```

16. Div
```html
<div></div>
```

17. Doctype
```html
<!DOCTYPE html>
<html>
</html>
```

18. Head
```html
<!DOCTYPE html>
<html>
  <head>
    <!-- metadata elements -->
  </head>
  <body>
    <!-- page contents -->
  </body>
</html>
```