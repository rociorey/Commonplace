


let socket = io();
let newText = document.getElementById('newText');


new Twitch.Player("twitch-embed", {
  channel: "ludwig"
});


//Setting up the submit button and linking it to the html id


//Setting up video space
// const video = document.getElementById('video');

//  Setting up the button on click
const button = document.getElementById('sendWord');
button.addEventListener('click',event => {

  // Getting the word input
  const mood = document.getElementById('mood').value;
  // Getting the current date
  const date = new Date().toLocaleString();
  // const date = new Intl.DateTimeFormat('en-GB', { dateStyle: 'full', timeStyle: 'long' }).format(dateOld);
  console.log(date);

  const data = {date, mood};
  // console.log(data);

  socket.emit('userInputData', data);

})
// button.addEventListener('click', async event => {
//     const mood = document.getElementById('mood').value;
   
//     const data = { mood };
//     const options = {
//       method: 'POST',
//       headers: {
//         'Content-Type': 'application/json'
//       },
//       body: JSON.stringify(data)
//     };
//     const response = await fetch('/api', options);
//     const json = await response.json();
//     console.log(json);
//   });

  // getData();

// async function getData() {
//   const response = await fetch('/api');
//   const data = await response.json();

//   for (item of data) {
//     const root = document.createElement('p');
//     const mood = document.createElement('div');
//     const date = document.createElement('div');

//     mood.textContent = ` ${item.mood}`;
//     const dateString = new Date(item.timestamp).toLocaleString();
//     date.textContent = dateString;

//     root.append(mood, date);
//     document.body.append(root);
//   }
//   console.log(data);
// }
// socket.on('welcome', (data)=> {
//     console.log("joined id: " + data);
//     // newText.innerHTML= 'This id is from socket.io connection for this page: ' + data;
// })


// function draw(){
//     noFill();
//     stroke(0);
//     rect(0,0,100,100);
// }