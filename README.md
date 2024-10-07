# RP2040 Pico Project Development Environment

This repository contains a development environment for building and deploying projects on the RP2040 microcontroller using the Raspberry Pi Pico SDK. It utilizes Docker, Docker Compose, and VS Code Dev Containers to create a consistent and portable development experience.

It creates an Ubuntu image and downloads the pico-sdk, picotool and clangd for a good development experience.

## Key Files

- `.devcontainer/devcontainer.json`: Contains the dev container configuration files for VS Code.
- `.devcontainer/Dockerfile`: The Docker image definition used to create the development environment.
- `.devcontainer/compose.yml`: Docker Compose file to manage the docker container.
- `workspace/src`: Folder containing your code.
- `workspace/clangd`: Include headers for clangd.
- `workspace/CMakeLists.txt`: CMake configuration file for building your project.
- `workspace/build/`: Folder where the build artifacts will be generated.

## Getting Started

### Prerequisites

Make sure you have the following software installed on your system:

- [Docker](https://www.docker.com/)
- [Docker Compose](https://docs.docker.com/compose/)
- [Visual Studio Code](https://code.visualstudio.com/)
  - With the extension [Remote - Containers](https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.remote-containers)

### Setting Up the Development Environment

1. **Clone the repository**

   ```bash
   git clone https://github.com/runiorr/pico-sdk-devcontainer.git
   cd pico-sdk-devcontainer
   ```

2. **Open the project in Visual Studio Code**

    open VS Code and navigate to File > Open Folder, then select the root of your project.

3. **Reopen in the Dev Container**

    You should see a prompt suggesting you reopen the project in the dev container. Click on "Reopen in Container." If you don't see the prompt, you can manually select Ctrl+Shift+P and choose Remote-Containers: Reopen in Container.

4. **Build the Project**

    Once inside the dev container, you can build the project using the following commands:

    ```bash
    Copy code
    mkdir -p build
    cd build
    cmake ..
    make
    ```

## Running and Deploying on the RP2040

After building your project, you can mount the rp2040 in your computer and just drag and drop the uf2 file generated in the build process into the microcontroller.

## Contributing

Contributions are welcome! Please create a fork of the repository and submit a pull request if you have improvements or bug fixes.
