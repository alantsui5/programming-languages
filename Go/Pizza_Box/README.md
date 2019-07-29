1. When returning object
   ```go
   return &Object
   return &Object{/*Content*/}
   ```
2. Calling Object from function
   ```go
   func callObject(ob *Object){
       /* Content */
   }
   ```
3. Point the specific object to new variable
    ```go
    r = Object{/*Content*/}
    
    rAlias = &r
    ```
4. Initialize Maps
   ```go
    Pizzas := make(map[string]*Pizza)
   ```