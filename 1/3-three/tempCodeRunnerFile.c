    printf("Enter an operator :(+ - * /)\n");
    scanf("%c",&operator);
    printf("enter the value of a:\n");
    scanf("%d"&num1);
    printf("enter the value of b:\n");
    scanf("%d"&num2);
    if(operator == '+'){
    result = num1 + num2;
    printf("%d + %d = %d\n",num1,num2,result);
    }
    // else if(){
        