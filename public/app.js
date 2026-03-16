const submitButton = document.getElementById('submit');
const input = document.getElementById('input');
const responseDiv = document.getElementById('response');

submitButton.addEventListener('click', () => {
    const text = input.value;
    // This is where you would typically make an API call to your C++ backend.
    // For this example, we'll just simulate the response.
    responseDiv.textContent = 'Processing: ' + text;
});
