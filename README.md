# ZEngine
A little game engine written in C++

## Introduction
This game engine is a personal project for learning about game development and graphics. It follows The Cherno's [Hazel Engine](https://www.youtube.com/watch?v=JxIZbV_XjAs&list=PLlrATfBNZ98dC-V-N3m0Go4deliWHPFwT&index=1) series, so take a look at it if you want to follow them too!

## How to build the project

This project has a Premake script which can be launched as follows:
```
GenerateProjects.bat
```
It will generate a Visual studio 2019 with all the needed configurations.

## Dev Diary
* 26/08/2021: 
  * Started the project!
  * Added EntryPoint
* 27/08/2021:
  * Added logging frontend (using the [spdlog](https://github.com/gabime/spdlog) library)
  * Added the [Premake](https://github.com/premake/premake-core) build system and premake5.lua script
