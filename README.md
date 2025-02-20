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

4. **Configure CMake** 
- Press `Ctrl+Shift+P` to open the Command Palette.
- Search for `CMake: Configure` and select it to begin configuration.
5. **Build the Project**: Press F7 to build the project
6. **Run the Game**: Click the small play button at the bottom bar in VS Code to execute the game.