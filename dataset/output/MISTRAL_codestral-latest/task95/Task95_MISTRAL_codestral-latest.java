// Java does not have a built-in function to get the processor time in seconds.
// However, you can use the following code to get the CPU time used by the current thread in nanoseconds.

long startTime = System.nanoTime();
// Your code here
long endTime = System.nanoTime();
long duration = (endTime - startTime) / 1000000000;  // divide by 1000000000 to get seconds
System.out.println("Processor time: " + duration + " seconds");