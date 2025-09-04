#include <stdio.h>
// Not important to understand how this struct is used for this lab
#include "structdefn.h"

employee fetch_employee_data( int emp_num_for_search ) {
	employee temp = {.emp_num = emp_num_for_search, 
	                 .name = "Thor, Odinson", 
			 .salary = 123456.78, 
			 .date_hired = "02/07/2015",
			 .dept_code = "D005" } ;
	printf("In fetch_employee_data. Found employee with id = %d\n", emp_num_for_search) ;
	
	return temp ;
	
}
