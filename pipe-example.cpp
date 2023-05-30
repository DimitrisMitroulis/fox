#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

using namespace std;
int main() {
    int pipefd[2];
    char buffer[5000];

    // Create the pipe
    pipe(pipefd);

    // Fork a child process
    int pid = fork();

    if (pid == 0) {
        // Child process
        //close(pipefd[1]);  // Close the write end of the pipe

        // Read data from the pipe
        read(pipefd[0], buffer, sizeof(buffer));
        cout << "Child process received: " << buffer << endl;

        close(pipefd[0]);  // Close the read end of the pipe
    } else {
        // Parent process
        // Write data to the pipe
        const char* message = "Hello from the parent!";
        write(pipefd[1], message, sizeof(message));

        close(pipefd[1]);  // Close the write end of the pipe
    }

    return 0;
}
