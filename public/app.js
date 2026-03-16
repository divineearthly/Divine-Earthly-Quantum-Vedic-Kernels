const submitButton = document.getElementById('submit');
const input = document.getElementById('input');
const responseDiv = document.getElementById('response');

submitButton.addEventListener('click', () => {
    const text = input.value;
    responseDiv.textContent = 'Processing: ' + text;

    fetch('/process', {
        method: 'POST',
        body: text
    })
    .then(response => response.text())
    .then(data => {
        responseDiv.textContent = data;
    })
    .catch(error => {
        console.error('Error:', error);
        responseDiv.textContent = 'Error: ' + error;
    });
});
