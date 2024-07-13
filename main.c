#include<stdio.h>

void registerSigHandler () ;

int processCommandLineOptions ( 
		int argc ,
		char *argv[] ,
		char *ip ,
		char *port ,
		char *hostname	) ;

int main ( int argc , char *argv[] ) { 


	char portbuf[8] , ip4buf[32] , hostnamebuf[128] ;
	char *port = portbuf ;
	char *ip = ip4buf ;
	char *hostname = hostnamebuf ;

	int ret;

	ret = processCommandLineOptions( 
			argc , 
			argv ,  
			ip ,
			port ,
			hostname	) ;
	if ( ret ) {
		printf("error: processCommandLineOptions()\n");
		return 1;
	}

	printf ( "main(): port: %s\n" , port ) ;
	printf ( "main(): ip: %s\n" , ip ) ;
	printf ( "main(): hostname: %s\n" , hostname ) ;

	return 0;
}
