#include<stdio.h>

char *ip ;
char *port ;
char *hostname ;

void printUsageInstructions () {

	printf ( "processCommandLineOptions(): \n" ) ;
	printf ( "processCommandLineOptions(): Usage examples: \n" ) ;
	printf ( "processCommandLineOptions(): $a.out (argc len = 1)\n" ) ;
	printf ( "processCommandLineOptions(): $a.out -p 8000  (argc len = 3)\n" ) ;
	printf ( "processCommandLineOptions(): $a.out -p 8000 -ip 192.168.1.100 (argc len = 5)\n" ) ;
	printf ( "processCommandLineOptions(): $a.out -p 8000 -ip 192.168.1.100 -hs localhost (argc len = 7)\n" ) ;
	printf ( "processCommandLineOptions(): $a.out -p 8000 -ip 192.168.1.100 -hs www.3deem.com (argc len = 7)\n" ) ;
	printf ( "processCommandLineOptions(): argc must be either 1, 3, 5 or 7\n" ) ;

}

void printoutOptions () {

	printf("processCommandLineOptions(): printoutOptions() port: %s\n", port ) ;
	printf("processCommandLineOptions(): printoutOptions() ip: %s\n", ip ) ;
	printf("processCommandLineOptions(): printoutOptions() hostname: %s\n", hostname ) ;

}

void setDefaults () {
	sprintf ( port , "8000" ) ;
	sprintf ( ip , "127.0.0.1" ) ;
	sprintf ( hostname , "localhost" ) ;
}

int processEachCommand ( char *optionCode , char *optionValue ) {

	if ( optionCode[0] == '-' ) {

		if ( optionCode[1] == 'p' ) {

			printf("processCommandLineOptions(): processEachCommand() optionCode is -p\n" ) ;
			sprintf ( port , "%s" , optionValue );

		} else if ( optionCode[1] == 'i' &&  optionCode[2] == 'p' ) {

			printf("processCommandLineOptions(): processEachCommand() optionCode is -ip  \n" ) ;
			sprintf ( ip , "%s" , optionValue );

		} else if ( optionCode[1] == 'h' &&  optionCode[2] == 'n' ) {

			printf("processCommandLineOptions(): processEachCommand() optionCode is -hn  \n" ) ;
			sprintf ( hostname , "%s" , optionValue );

		} else {

			printf("processCommandLineOptions(): processEachCommand(): Error Unknow Option Code  \n" ) ;
			return 3;
		}


	} else {

		printf("processCommandLineOptions(): processEachCommand(): options must start with a '-'\n" );
		return 2;

	}

	printf("processCommandLineOptions(): processEachCommand() optionValue: %s\n", optionValue ) ;

	return 0;

}

int processCommandLineOptions ( 
		int argc , char *argv[] , 
		char *_ip , char *_port , char *_hostname 
		) {

	ip = _ip ;
	port = _port ;
	hostname = _hostname ;

	printUsageInstructions () ;

	setDefaults () ;

	int ret;

	if ( argc == 1 ) {
		printf ( "processCommandLineOptions(): argc: %d\n", argc ) ;

	} else if ( argc == 3 ) {
		printf ( "processCommandLineOptions(): argc: %d\n", argc ) ;
		ret = processEachCommand( argv[1] , argv[2] ); if ( ret ) return 3;

	} else if ( argc == 5 ) {
		printf ( "processCommandLineOptions(): argc: %d\n", argc ) ;
		ret = processEachCommand ( argv[1] , argv[2] ); if ( ret ) return 5;
		ret = processEachCommand ( argv[3] , argv[4] ); if ( ret ) return 5;

	} else if ( argc == 7 ) {
		printf ( "processCommandLineOptions(): argc: %d\n", argc ) ;
		ret = processEachCommand( argv[1] , argv[2] ); if ( ret ) return 7;
		ret = processEachCommand( argv[3] , argv[4] ); if ( ret ) return 7;
		ret = processEachCommand( argv[5] , argv[6] ); if ( ret ) return 7;

	} else {

		printf("processCommandLineOptions(): Usage error, argc must be either 1 , 3 , 5 or 7\n");
		return 1;

	}

	printoutOptions () ;

	

	return 0;

}
