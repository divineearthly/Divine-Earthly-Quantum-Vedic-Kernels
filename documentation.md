
# Divine Kernel and Earthly Web Documentation

This document provides a comprehensive overview of the Divine Kernel and the Divine Earthly Web application, including their architecture, setup, and usage.

## 1. Divine Kernel (`divine_kernel`)

The Divine Kernel is the core C++ application that simulates a futuristic, spiritually-inspired operating system.

### 1.1. Architecture

The kernel is designed around the concept of "Sutras"—small, independent modules that perform specific tasks. These Sutras are registered with a central `SutraRegistry` and can be invoked dynamically. The kernel's operation is orchestrated by a state machine that cycles through different states (Gunas), representing different operational modes.

Key Components:
- **`main.cpp`**: The main entry point of the application. It initializes the kernel, registers the Sutras, and starts the main operational loop.
- **`include/core/SutraRegistry.h`**: A singleton class that manages the registration and invocation of all Sutras.
- **`src/batch*_reg.cpp`**: These files are responsible for registering batches of Sutras with the `SutraRegistry`.

### 1.2. Setup and Compilation

To compile the Divine Kernel, simply run the `make` command from the root of the project:

```bash
make
```

This will create the `divine_kernel` executable in the root directory.

### 1.3. Usage

To run the kernel, execute the compiled binary:

```bash
./divine_kernel
```

The kernel will then start its operational cycle, printing status messages from the various Sutras and subsystems to the console.

### 1.4. Registered Sutras

The following Sutras are registered with the kernel:

- `vedic_alu`: A Vedic Arithmetic Logic Unit.
- `saraswati_stream`: A natural language processing stream.
- `yoga_attention`: A Yoga-inspired attention mechanism.
- `panini_grammar`: A Panini-inspired grammar engine.
- `nyaya_inference`: A Nyaya-inspired inference engine.
- `sulba_geometry`: Geometric routines from the Sulba Sutras.
- `surya_trig`: Trigonometric approximations from the Surya Siddhanta.
- `buddhi_fuzzy`: A fuzzy logic inference engine.
- `quantum_heuristic`: A quantum-inspired heuristic.

## 2. Divine Earthly Web (`divine-earthly-web`)

The Divine Earthly Web is a Laravel-based web application that provides a front-end interface for the Divine Kernel.

### 2.1. Architecture

This is a standard Laravel application that includes:
- **Routes**: Defined in `routes/web.php` and `routes/console.php`.
- **Controllers**: Located in `app/Http/Controllers`.
- **Views**: Blade templates in `resources/views`.
- **Front-end Assets**: CSS and JavaScript files in `resources/css` and `resources/js`, which are compiled using Vite.

### 2.2. Setup

1. **Install PHP Dependencies**: Navigate to the `divine-earthly-web` directory and install the required PHP packages using Composer:

   ```bash
   cd divine-earthly-web
   composer install
   ```
   *(Note: If `composer` is not installed, you will need to install it first.)*

2. **Install JavaScript Dependencies**: Install the front-end dependencies using npm:

   ```bash
   npm install
   ```

3. **Build Front-end Assets**: Compile the CSS and JavaScript assets using Vite:

   ```bash
   npm run build
   ```

### 2.3. Usage

To run the web application, you will need to:
1.  Configure a web server (like Nginx or Apache) to point to the `public` directory of the Laravel application.
2.  Set up a `.env` file with your database and other configuration details.
3.  Run the Laravel development server (for local development): `php artisan serve`.

