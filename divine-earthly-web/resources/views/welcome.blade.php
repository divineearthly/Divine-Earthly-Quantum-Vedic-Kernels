<!DOCTYPE html>
<html lang="{{ str_replace('_', '-', app()->getLocale()) }}">
<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>Divine Earthly Quantum Kernels</title>
    <link href="https://fonts.googleapis.com/css2?family=Orbitron:wght@400;700&display=swap" rel="stylesheet">
    <style>
        body {
            background-color: #1a1a1a;
            color: #e0e0e0;
            font-family: 'Orbitron', sans-serif;
            display: flex;
            justify-content: center;
            align-items: center;
            height: 100vh;
            margin: 0;
        }
        .container {
            text-align: center;
        }
        h1 {
            font-size: 3rem;
            color: #00ffcc;
            text-shadow: 0 0 15px #00ffcc;
            margin-bottom: 2rem;
        }
        .button {
            background-color: #00ffcc;
            color: #1a1a1a;
            border: none;
            padding: 15px 30px;
            font-size: 1.2rem;
            font-family: 'Orbitron', sans-serif;
            cursor: pointer;
            border-radius: 5px;
            transition: all 0.3s ease;
            box-shadow: 0 0 10px #00ffcc;
        }
        .button:hover {
            background-color: #1a1a1a;
            color: #00ffcc;
            border: 1px solid #00ffcc;
        }
        .output-area {
            margin-top: 2rem;
            background-color: #2a2a2a;
            padding: 20px;
            border-radius: 5px;
            text-align: left;
            white-space: pre-wrap;
            font-family: monospace;
            min-height: 100px;
            border: 1px solid #00ffcc;
        }
    </style>
</head>
<body>
    <div class="container">
        <h1>Divine Earthly Quantum Kernels</h1>
        <button class="button" id="run-kernel-btn">Run Kernel</button>
        <div class="output-area" id="output"></div>
    </div>

    <script>
        document.getElementById('run-kernel-btn').addEventListener('click', function() {
            document.getElementById('output').innerHTML = 'Executing Kernel...';
            fetch('/run-kernel')
                .then(response => response.json())
                .then(data => {
                    document.getElementById('output').innerHTML = data.output;
                });
        });
    </script>
</body>
</html>
