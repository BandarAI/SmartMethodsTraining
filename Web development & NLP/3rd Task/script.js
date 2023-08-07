const texts = document.querySelector('.texts'); 

window.SpeechRecognition = window.SpeechRecognition || window.webkitSpeechRecognition;
const recognition = new window.SpeechRecognition();
recognition.interimResults = true;

let p = document.createElement('p');

recognition.addEventListener('result', (e) => {
    const text = Array.from(e.results)
        .map(result => result[0])
        .map(result => result.transcript)
        .join('');

    p.textContent = text;
    texts.appendChild(p);

    if(e.results[0].isFinal)
    {
      p = document.createElement('p');
    }

    console.log(text);

    InsertIntoDB(text);
});

recognition.addEventListener('end', (e) => {
    recognition.start();
});

recognition.start();

function InsertIntoDB(text) {
    const xhr = new XMLHttpRequest();
    xhr.open('POST', 'db.php', true);
    xhr.setRequestHeader('Content-Type', 'application/x-www-form-urlencoded');
    xhr.onreadystatechange = function() {
        if (xhr.readyState === XMLHttpRequest.DONE && xhr.status === 200) {
            console.log(xhr.responseText);
        }
    };
    xhr.send('texts=' + encodeURIComponent(text)); 
}
