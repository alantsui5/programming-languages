function onlyAlphabet(character){
    if((character>='a' && character<='z') || (character>='0' && character<='9'))
      return character;
  }
  
  function palindrome(str) {
    // Good luck!
    var originalString = str.toLowerCase().split("").filter(onlyAlphabet).join("")
    var palindrome = originalString.toLowerCase().split("").reverse().join("");
    
    return originalString==palindrome;
  }