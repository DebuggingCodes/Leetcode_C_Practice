int reverse(int x){
    if(x==-2147483648){
        return 0;
    }
    int power=0,min=0,res;
    long reverse=0;
    if(x<0){
        min=-x;
    }
    else{
        min=x;
    }
    if(x==0){
        return 0;
    }
    if(min%10==0){
        while(min%10==0){
            min=min/10;
        }
    }
    while(min>pow(10,power)){
        power++;
    }
    if (power==0&&x>0){
        return min;
    }
    if (power==0&&x<0){
        return -min;
    }
    //power done
    int *solver= (int*)malloc(power * sizeof(int));
    //dynamic array done
    for(size_t i=0;i<power;i++){
        solver[i]=min/(pow(10,i));
    }
    
    //power is running smoothly
    int j=power-1;
    for(int i =0;i<power;i++){
        if(i!=power-1){
            do{
                reverse+= (solver[i]-solver[i+1]*10)* pow(10,j);
            }while(1==2);
        }
        else{
            reverse+=solver[i];
        }
        j--;
    }
    free(solver);
    if(reverse>INT_MAX){
        return 0;
    }
    else{
        res=(int)reverse;
    }
    if(x<0){
        return -res;
    }
    return res;
}
