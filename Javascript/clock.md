​	13/04/2019 12:51

> Topic Video

<iframe width="560" height="315" src="https://www.youtube.com/embed/ZSCdTfWEK_8" frameborder="0" allow="accelerometer; autoplay; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>

# Clock

## Aim

1. HTML
   1. Material
2. CSS
   1. Seting the rotations of clock hand
   2. 'Playing with the animation for clock hand

3. Javascript
   1. Bind the Current date to the clock
   2. Convert time to degrees of rotation
   3. Apply to the clock hand



## Steps

### Material

```html
<div class="clock">
  <div class="clock-dace">
    <div class"hand hour-hand"> </div>
    <div class"hand min-hand"> </div>
    <div class"hand second-hand"> </div>
  </div>
</div>
```

```css
html {
      background: #018DED url(http://unsplash.it/1500/1000?image=881&blur=50);
      background-size: cover;
      font-family: 'helvetica neue';
      text-align: center;
      font-size: 10px;
    }
    body {
      margin: 0;
      font-size: 2rem;
      display: flex;
      flex: 1;
      min-height: 100vh;
      align-items: center;
    }
    .clock {
      width: 30rem;
      height: 30rem;
      border: 20px solid white;
      border-radius: 50%;
      margin: 50px auto;
      position: relative;
      padding: 2rem;
      box-shadow:
        0 0 0 4px rgba(0,0,0,0.1),
        inset 0 0 0 3px #EFEFEF,
        inset 0 0 10px black,
        0 0 10px rgba(0,0,0,0.2);
    }
    .clock-face {
      position: relative;
      width: 100%;
      height: 100%;
      transform: translateY(-3px); 
      /* account for the height of the clock hands */
    }
    .hand {
      width: 50%;
      height: 6px;
      background: black;
      position: absolute;
      top: 50%;
    }
```

1. Change origin of rotation to the center of clock

   ```css
   .hand{
     transform-origin: 100%;
   }
   ```

2. Change default to 12:00 am

   ```css
   .hand{
     transform: rotate(90deg);
   }
   ```

3.  Make the hand moving animation

   ```css
   .hand{
     transition: all 0.05s;
     /* Can be tested and modify in chrome */
     transition-timing-function: cubic-beizer(0.1,0.27,0.58,1);
   }
   ```

4. Set Code run every 1s

   ```javascript
   const setDate = () => {
     console.log('Hi');
   }
   
   setInterval(setDate, 1000);
   ```

5. Get hour, minute and second

   ```Javascript
   const setDate = () => {
     const now = new Date();
     
     //Seconds
     const seconds = now.getSeconds();
     
     //Minutes
     const mins = now.getMinutes();
     
     //Hour
     const Hour = now.getHours();
     console.log(seconds);
   }
   ```

6. Convert second, minute and hour to degrees

   ```javascript
   const setDate = () => {
     const now = new Date();
     
     //Seconds
     const seconds = now.getSeconds();
     // + 90 is to deal with the offset in the css
     const secondDegrees = (seconds/60)*360+90;
     console.log("seconds: " + seconds);
     
     //Minutes
     const mins = now.getMinutes();
     const minDegrees = (seconds/60)*360 + 90;
     console.log("minute: "+ mins);
     
     //Hour
     const hour = now.getHours();
     const hourDegrees = (seconds/60)*360 + 90;
     console.log("hour: "+ hour);
   }
   ```

7. Apply the rotation degree to clock hand

   ```javascript
   //Seconds
   const secondHand = document.queryselector('.second-hand');
   //Minutes
   const minHand = document.queryselector('.min-hand');
   //Hours
   const minHand = document.queryselector('.hour-hand');
   
   const setDate = () => {
     const now = new Date();
     
     //Seconds
     const seconds = now.getSeconds();
     // + 90 is to deal with the offset in the css
     const secondDegrees = (seconds/60)*360+90;
     console.log("seconds: " + seconds);
     secondHand.style.transform = `rotate(${secondsDegrees}deg)`;
     
     //Minutes
     const mins = now.getMinutes();
     const minDegrees = (seconds/60)*360 + 90;
     console.log("minute: "+ mins);
     minHand.style.transform = `rotate(${minsDegrees}deg)`;
     
     //Hour
     const hour = now.getHours();
     const hourDegrees = (seconds/60)*360 + 90;
     console.log("hour: "+ hour);
     hourHand.style.transform = `rotate(${hourDegrees}deg)`;
   }
   ```

   