# RaytraCer

RaytraCer is a raytracer written in C++ as the name does not suggests.

## Set-up 
 
 You need to have at least CMake 3.14 installed. Clone the sdl folder in vendored/sdlsomething
 ```bash
 git clone https://github.com/libsdl-org/SDL vendored/SDL
 ```
 You can set-up the build folder using
 ```bash
 cmake -S . -B .\build\
 ```

 And build for release mode with:

```bash
 cmake --build .\build\ --config Release
```
 `
