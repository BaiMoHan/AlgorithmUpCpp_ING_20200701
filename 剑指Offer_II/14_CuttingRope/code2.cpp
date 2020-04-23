int maxProductAfterCutting_solution(int length)
{
    if(length<2)
        return 0;
    if(length==2)
        return 1;
    if(length==3)
        return 2;

    int timeOf3=length/3;

    if(length-timeOf3*3==1)
        timeOf3-=1;

    int timeOf2=(length-timeOf3*3)/2;

    return (int)(pow(3,timeOf3))*(int)(pow(2,timeOf2));
}