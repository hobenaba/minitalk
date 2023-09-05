# The project is about :
As implied by its name, it's a simple form of communication between two programs: the client and the server, utilizing Unix signals (SIGUSR1 and SIGUSR2).The process starts with the launch 
of the server executable, which displays its Process ID (PID). Subsequently, when running the client executable, you provide this PID as input along with the desired message.
# Plan :
I took my message and processed it by converting each character into its binary form. Then, I sent the signals, where each signal represented a specific meaning (SIGUSR1 for '1' and SIGUSR2 for '0'). When the signal reaches the other program, I perform the opposite process of what I did in the client: I assemble the binary data back into the original character and then print it.
