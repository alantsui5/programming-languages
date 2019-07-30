#  Reminder on swift

1. Scanning `Int`
    ```swift
    let number = Int(readLine(strippingNewline: true)!)!
    ```
2. Scanning `Array`
    ```swift
    let stringArray = readLine(strippingNewline: true)!.characters.split {$0 == ” “}.map (String.init)
    ```
3. `!` and `?` notation 
<br />
    > `?` allow null
    > `!` assert null
