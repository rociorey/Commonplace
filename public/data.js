let socket = io();
let newText = document.getElementById('newText');


// new Twitch.Player("twitch-embed", {
//   channel: "rocioreyaloe",
//   height:400,
//   width:620
// });


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

  document.getElementById('mood').value='';
  

})
