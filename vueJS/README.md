# Learning vue

* Init variables
  ```js
  var app = new Vue({
    el: '#app',
    data: {
      message: 'Hello World!'
    }
  })
  ```
* Using variables
  ```html
  {{ message }}
  ```
* Modifying variables
    ```js
    app.message = "New Value"
    ```
    
* `v-bind:<Command>`
  Use the html attributes with bind