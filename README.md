# cpp_tutorials

<h2>Project Structure</h2>

<b>bin:</b> The output executables go here, both for the app and for any tests.

<b>build:</b> This folder contains all object files, and is removed on a clean.

<b>doc:</b> Any notes, like my assembly notes and configuration files, are here. I decided to create the development and production config files in here instead of in a separate config folder as they “document” the configuration.

<b>include:</b> All project header files. All necessary third-party header files that do not exist under /usr/local/include are also placed here.

<b>lib:</b> Any libs that get compiled by the project, third party or any needed in development. Prior to deployment, third party libraries get moved to /usr/local/lib where they belong, leaving the project clean enough to compile on our Linux deployment servers. I really use this to test different library versions than the standard.

<b>src:</b> The application and only the application’s source files.

<b>test:</b> All test code files.


<h2>Build the Project with Cmake</h2>

You should run the following commands to compile the project:

> cd build

> make clean

> cmake -DCMAKE_BUILD_TYPE=[Debug|Release] ..

> make

> make install

Then run the application:

> ./main


<h2>Generating Doxygen Documentation</h2>

If <code>doxygen.conf</code> file does not exist, then create it before generate the documentation.

> doxygen -g doxygen.conf

Change the followings:

<code>PROJECT_NAME           = "CPP Tutorials"</code>

<code>OUTPUT_DIRECTORY       = doc</code>

<code>RECURSIVE              = YES</code>

You should run the following commands to generate the doxygen documentation:

> doxygen doxygen.conf
