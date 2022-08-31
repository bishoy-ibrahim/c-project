printf("please enter the student ID : ");
        scanf("%d",id);
        printf("please enter the student year : ");
        scanf("%d",id);
        for(int i=0;i<3;i++){
            printf("please enter course no.%d Id : ",i+1);
            scanf("%d",subjects[i]);
            printf("please enter course no.%d grade : ",i+1);
            scanf("%d",grades[i]);
        }
