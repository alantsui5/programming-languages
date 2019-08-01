K Date : 10/04/2019 23:2

> Topic Video

<iframe width="560" height="315" src="https://www.youtube.com/embed/ceRuAuiP6v4" frameborder="0" allow="accelerometer; autoplay; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>

# Virtual Drum

## Aim

1. Make Animations and player class
2. Select DOM with Keyboard Keys
3. Select and make audioplay
   1. Select Audio play
   2. audioplay
   3. Reset time
4. Add player Class
   1. Select div
   2. add class
   3. destroy class

## Steps

### Material

```css
.playing{
  transform:scale(1.1);
  border-color:#ffc600;
  box-shadow: 0 0 10px #ffc600;
}
.the-div{
  transition: all 0.07s
}
```

1. Adding Binding from key to DOM

   > Reference: http://keycode.info

   ```html
   <!-- Simple Example -->
   <!-- data-key="65" is the binding-->
   <div data-key="65" class="the-div">
     haha2
   </div>
   <audio data-key="65" src="sounds/sounds1.wav"></audio>
   ```

2. Listening Keydown Event

   ```javascript
   //e stands for event
   window.addEventListener('keydown',(e)=>{
     console.log(e);
     console.log(e.keyCode);
   });
   ```

   

3. Select audio element with data attribute ```data-key```

   ```javascript
   window.addEventListener('keydown',(e)=>{
     const audio = document.querySelecter(`audio[data-key='${e.keyCode}']`);
     if(!audio) return;
     console.log(audio);
   });
   ```

4. Play the element with ```audio.play()```

   ```javascript
   window.addEventListener('keydown',(e)=>{
     const audio = document.querySelecter(`audio[data-key='${e.keyCode}']`);
     if(!audio) return;
     audio.play();
   });
   ```

5. Remove the delay with time reset

   ```javascript
   window.addEventListener('keydown',(e)=>{
     const audio = document.querySelecter(`audio[data-key='${e.keyCode}']`);
     if(!audio) return;
     audio.currentTime=0;
     audio.play();
   });
   ```

6. Add class ```'playing'``` in the box

   ```javascript
   window.addEventListener('keydown',(e)=>{
     const audio = document.querySelecter(`audio[data-key='${e.keyCode}']`);
     if(!audio) return;
     audio.currentTime=0;
     audio.play();
     //New
     key.classList.add('playing');
   });
   ```

   

7. Remove ```'playing'``` after transition

   ```javascript
   //2
   (e) => {
     console.log(e);
     if(e.propertyName !== 'transition') return;
     console.log(e, propertyName);
     console.log(this);
     this.classList.remove('playing');
   }
   
   
   //1
   const keys = document.querySelectorAll('.key');
   key.forEach(key => key.addEventListener('transitioned', removePlaying))
   ```

   

8. Refactor the 'playing sound' event listener

   ```javascript
   const playSound = (e)=>{
     const audio = document.querySelecter(`audio[data-key='${e.keyCode}']`);
     if(!audio) return;
     audio.currentTime=0;
     audio.play();
     //New
     key.classList.add('playing');
   }
   
   //Code of transitions...
   
   
   window.addEventListener('keydown',playSound);
   ```

   