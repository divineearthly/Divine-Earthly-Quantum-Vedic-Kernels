<?php

use Illuminate\Support\Facades\Route;
use App\Http\Controllers\DivineKernelController;

Route::get('/', function () {
    return view('welcome');
});

Route::get('/run-kernel', [DivineKernelController::class, 'runKernel']);
