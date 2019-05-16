fibonacci <- function(n){
	if(n<=2)
		1
	else
		fibonacci(n-1) + fibonacci(n-2)
}
	memoria = rep(-1,2)
fiboDinamico <- function(n){
	memoria <<- rep(-1,n)	
	fibo(n)
}

fibo <- function(n){
	if(memoria[n]!=-1){}
	else if(n<=2)
		memoria[n] <<- 1
	else
		memoria[n] <<- fibo(n-1) + fibo(n-2)
	memoria[n]
}