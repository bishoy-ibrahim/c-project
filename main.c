#include <stdio.h>
#include <stdlib.h>
#include "SDB.h"
typedef unsigned long int uint8 ;
typedef struct n
{
    uint8 student_id ;
    uint8 student_year ;
    uint8 course_id [3] ;
    uint8 course_grade [3] ;
    struct n* link ;

}node ;

node *start=NULL ;

int main()
{

    return 0;
}
