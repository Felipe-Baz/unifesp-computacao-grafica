echo "start running"
nix-shell -p libGL libGLU freeglut --run '
    # Command 1
    echo "Running GCC compile command"
    bash -c "time gcc main.c -lglut -lGL -lGLU -lm -o main" > >(tee -a output.log) 2>&1

    # Command 2
    echo "Starting compiled program"
    bash -c "./main"

    # Example Command 3
    #echo "Running Command 3"
    #bash -c "echo hmm3"
'
#gcc test.c -lglut -lGL -o testprog