<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;
use Symfony\Component\Process\Process;

class DivineKernelController extends Controller
{
    public function runKernel()
    {
        // Path to your C++ project
        $cppProjectPath = realpath(__DIR__ . '/../../..');

        // Commands to compile and run your C++ application
        $commands = [
            'cd ' . $cppProjectPath,
            'g++ -std=c++17 -O3 -march=native -ffast-math -Wall -Iinclude main.cpp memory/GarudaShredder.cpp compute/YogaAttention.cpp memory/AkashicRecords.cpp -o build/divine_kernel',
            $cppProjectPath . '/build/divine_kernel'
        ];

        // Execute the commands
        $process = Process::fromShellCommandline(implode(' && ', $commands));
        $process->run();

        // Get the output
        $output = $process->getOutput();

        return response()->json(['output' => $output]);
    }
}
