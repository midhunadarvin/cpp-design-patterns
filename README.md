# C++ Plugin Architecture

Based on chapter 2 of the book [.NET Design patterns by Praseed Pai](https://www.amazon.in/NET-Design-Patterns-Praseed-Pai/dp/1786466155). 

This project consists of a simple tax computation program. The tax computation logic is based upon the archetypes ( Eg. SeniorCitizen, OrdinaryCitizen etc ) in the system. 

The tax liability for each archetype is computed based on several tax parameters. This is done via a plugin architecture to make the software extensible so that we can update the system logic without impacting the application. 

This project utilises the following design patterns :

1. Facade 
2. Command Method
3. Design By Contract
4. Factory
5. Template Method 

### Prerequisite

Make
`https://www.gnu.org/software/make`

CMake
`https://cmake.org/install/`


### Development setup

This command will clone the project and it's submodules ( dependencies ) . We only have one dependency [tinyxml2](https://github.com/leethomason/tinyxml2) to load the `config.xml` file and parse it.

```
git clone --recurse-submodules
````

### Build 

The build process comprises of two steps. 

##### 1. Build the commands ( aka. the plugins ) of the application

The following terminal commands will build the plugins available in the `commands` folder. It will be available as a Mach-O dynamic library file ( .dylib ) in MacOS and Shared Object library file ( .so ) in Linux .

```
cd commands;
mkdir build;
cd build;
cmake ..;
make;
```

##### 2. Build the application

Go to the root folder of the project and execute the following terminal commands
```
./build_libs.sh
mkdir build;
cd build;
cmake ..;
make;
```

This will build the application and the compiled output will be in the location `build/CppPluginArch`


#### TODOs

- Pass the config.xml file location and the commands folder location as env variables. Currently it is hard-coded, please note you will have to update the path in the code before building.
