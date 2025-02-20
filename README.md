## About
This project is a simple Tetris game developed as part of the Advanced Programming Course (Course Code: 2425II_INT2215_7) at VNU-UET. The primary goal of this project is to gain hands-on experience in software development, utilizing programming languages and their libraries, while also practicing code modularization and refactoring.

## Author
Nguyen Ba Hoang Minh (Student ID: 24021568)

## Requirements
Before setting up this project, ensure you have the following installed on your local machine:
- [CMake](https://cmake.org/download/) – Build system generator.
- [Ninja](https://github.com/ninja-build/ninja/releases) – Build system.
- [C/C++ Extension Pack](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools-extension-pack) - Required for Visual Studio Code.

## Development Setup
Follow these steps to set up and run the project:

1. **Fork and Clone**: Fork this repository to your remote account and clone it onto your local machine. 
2. **Open in VS Code**: Launch [Visual Studio Code](https://code.visualstudio.com/) and open the cloned repository.
3. **Install Dependencies**: Open the terminal at the project's root directory and run:

    ```
    vcpkg install
    ```

    This will install the necessary packages, including [raylib](https://www.raylib.com/). Once completed, a folder named `/vcpkg_installed` should appear at the top level of the project.

4. **Configure CMake** : Run the following command to create a CMake configuration: 

    ```
    cmake -S . -B out/build/tetris -G "Ninja"
    ```

5. **Build the Project**: Navigate to the build directory and run Ninja to compile the project: 

    ```
    cd out/build/tetris
    ninja
    ```

6. **Run the Game**: Once the build is complete, run the executable: 

    ```
    ./tetris.exe
    ```