1. When returning object
   ```go
   return &Object
   return &Object{/*Content*/}
   ```
2. Calling Object from function
   ```go
   //Write to object
   func (ob *Object)callObject() string{
       /* Content */
   }
    //Read only
    func (ob Object)callObject(param string){
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
5. Creating Objects
   ```go
   e := new(ClassName)
   e := &ClassName{}
   ```
6. Creating new projects in go
   ```sh
   #inside project dir
   go mod init <projectName>
    # import local packages
    import "<projectName>/<packageName>"
    ```

7. Golang Installation
   
Credit:
https://medium.com/@john.lin/golang-%E5%AD%B8%E7%BF%92%E7%AD%86%E8%A8%98-582cad359738
https://gobyexample.com/
https://github.com/go-training/training/tree/79ae76dd120c39949d99b4fcb69d692880200ad4
http://www.golangprograms.com/go-language/struct.html

https://github.com/go-training/training/tree/79ae76dd120c39949d99b4fcb69d692880200ad4
https://github.com/giorgisio/goav
https://github.com/elliotchance/c2go
https://www.youtube.com/watch?v=jJS6G7irZSc
https://www.youtube.com/channel/UC_BzFbxG2za3bp5NRRRXJSw/videos
https://www.youtube.com/channel/UC2GHqYE3fVJMncbrRd8AqcA/videos
https://www.youtube.com/channel/UCsf0cZc4jnvE5-CjEhWN8pg/videos
https://www.youtube.com/user/gocoding/videos
