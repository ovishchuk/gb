Linux Makefile

NOTE: 
    All actions are considered to be done from working directory

1. Build:

        $ make

    'build' directory will be created with library and executable inside

2. Install:

        $ sudo make install

3. Run:

        $ ./build/ttt

    from work directory or

        $ ttt

    after installation.
    You can also use relative path to ./build/ttt

4. Uninstall:

        $ sudo make uninstall

5. Clean:

        $ make clean

    to remove all build items.



P.S.: 

    You can also build with:

        $ g++ main.cpp tiktaktoe.cpp -o ttt
    
    and run

        $ ./ttt

    Why not? ;-)