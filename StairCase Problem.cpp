# Dynamic_Programming--1

long fib(int n, long output[])
{
    
    
    if(n==0 || n==1)
    {
        return 1;
    }
    
    if(n==2)
        return 2;
    
    if(output[n]>0)
    return output[n];
    
    long sa=fib(n-1,output)+fib(n-2,output)+fib(n-3,output);
    output[n]=sa;
    
    
    return sa;
}

long staircase(int n)
{
	long output[n+1]={0};
    fib(n,output);
}
