BOUTANT Thomas
Test for vacancy "Junior Embedded Developer (C/C++)" - Kyiv
Made between 27 and 29 November 2017


# Exercise 1:
--------------------------------------------------------------------------
Write a script to Bash that displays the following information:
- Linux kernel version (version only, example: 4.9.0-4-686)   
- IP machines
- MAC address of the network card
- Defines the number of processor cores and displays the current load of each core
- Number of free, occupied, shared RAM in GB

The script should be with comments
--------------------------------------------------------------------------
- Made in less than 1 hour (I knew the second exercice were longer). I'm not sure about the last information if I did it correctly (for the current load of each core, I've used a simple instruction for instance)...




# Exercise 2:
--------------------------------------------------------------------------
 Implement a console client-server application using Qt5.3.0 library, qmake build system and g ++ compiler - 4.8.
 The client and the server must communicate via sockets and support any arbitrary set of commands and the ability to write and read the value of arbitrary parameters to the server.
 Example commands: START, STOP, SET_PARAM (key, value), GET_PARAM.
 Implement the output of the help menu for the client with the -h or --help command, which contains a list of available commands. As an IPC, use QTcpSocket.
 It will be a plus if the server can simultaneously support several clients, for example, 5.
--------------------------------------------------------------------------
- I took one evening to install QTCreator on my computer and to understand how it works. Usually, I use Microsoft Visual Studio.
- I've used once QT in classrooms (during 2 hours). It was in October 2017.
- Last year, I had a similar homework to do, but in C. We used Multithreading (and we managed the memory: malloc, free...). I didn't have time for that here.
- The program is not finished : there can be several clients, but they can't be simultaneously activ on the server.
- For the commands, I didn't have a lot of ideas about what to implemente...
