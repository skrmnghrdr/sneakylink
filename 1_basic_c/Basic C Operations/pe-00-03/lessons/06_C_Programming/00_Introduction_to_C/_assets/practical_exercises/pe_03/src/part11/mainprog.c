#include <stdio.h>
#include "fetchprog.h"
#include "structdefn.h"

int main( )
{	
	employee joe_dokes = fetch_employee_data( 12 );
	printf("In main(). Employee name found: %s\n", joe_dokes.name) ;
}
