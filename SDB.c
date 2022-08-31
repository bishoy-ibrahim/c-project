extern node *start ;

void AddAtbeginning (uint8 id,uint8 years,uint8*subjects,uint8*grades)
{
    node *temp=(node*)malloc(sizeof(node));

    if (temp!=NULL){
        start->link=temp ; //link start with the first node
        temp->link=NULL ; //point the firs node to NULL

        temp->student_id= id ; //get the student ID
        temp->student_year= years ; //get the student year

        for(int i=0;i<3;i++){
           temp->course_id[i]=subjects[i]; //get the course ID
           temp->course_grade[i]=grades[i]; //get the course grade
         }
    }
}



node* AddAtEnd (uint8 id,uint8 years,uint8*subjects,uint8*grades)
{

    node *temp=(node*)malloc(sizeof(node));
    node *ptr = start ;

    if (temp!=NULL){

        while(ptr->link!=NULL)
            ptr=ptr->link ;
        temp->link = NULL ;
        ptr->link = temp ;

        temp->student_id= id ; //get the student ID
        temp->student_year= years ; //get the student year

        for(int i=0;i<3;i++){
           temp->course_id[i]=subjects[i]; //get the course ID
           temp->course_grade[i]=grades[i]; //get the course grade
         }
    }
    while(ptr->link!=NULL)
            ptr=ptr->link ;
    return ptr ;
}



bool SDB_AddEntry (uint8 id,uint8 years,uint8*subjects,uint8*grades)
{
    bool full_flag=SDB_isFull ;
    if (full_flag){
        printf ("Sorry you can't enter any data the list if full");
        return 0 ;
    }
    else{
            if (start==NULL){
              AddAtbeginning(id,years,subjects,grades);
              if (start==NULL)
                return 0 ;
              else if (start->link==NULL)
                return 1 ;
          }
          else{
              node *ptr=NULL ;
              ptr=AddAtEnd(id,years,subjects,grades);
              if (ptr->student_id==id)
                  return 1 ;
             else
                 return 0 ;
          }
    }


}



bool SDB_isFull (void)
{
    int i = 0 ;
    node *ptr = start ;
    while (ptr->link!=NULL){
        ptr=ptr->link ;
        i++ ;
    }
    i++ ;
    if (i==10)
        return 1 ;
    else
        return 0 ;
}



uint8 SDB_GetUsedSize (void)
{
    uint8 i=0 ;
    node *ptr = start ;
    while (ptr->link!=NULL){
        ptr=ptr->link ;
        i++ ;
    }
    i++ ;
    return i ;
}



bool SDB_ReadEntry (uint8 id,uint8*years,uint8*subjects,uint8*grades)
{
    node *ptr =start ;
    while(ptr!=NULL){
        if (ptr->student_id!=id)
            ptr=ptr->link ;
        else
            break ;
    }
    if (ptr->student_id==id){
        *years=ptr->student_year ;
        for(int i=0;i<3;i++){
            subjects[i]=ptr->course_id[i];
            grades[i]=ptr->course_grade[i];
        }
        return 1 ;
    }
    else
        return 0 ;

}



bool SDB_IsIdExist(uint8 id)
{
    node *ptr =start ;
    while(ptr!=NULL){
        if (ptr->student_id!=id)
            ptr=ptr->link ;
        else
            break ;
    }
    if (ptr->student_id==id)
        return 1 ;
    else
        return 0 ;

}
